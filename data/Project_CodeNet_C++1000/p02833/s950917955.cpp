#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

template<typename T>
static inline void chmin(T & ref, const T  value) {
	if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T & ref, const T value) {
	if (ref < value) ref = value;
}

template <typename X, typename M>
struct SegTreeLazyProportional {
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    using FM = function<M(M, M)>;
    using FP = function<M(M, int)>;
private:
    int n;
    FX query_Value_;
    FA merge_data_and_lazy_;
    //遅延評価するときに子に伝番させる方法
    FM updateLazy_;
    //遅延評価値と長さから何をするか決める
    FP evaluateLazyLength_;
    //無効値
    const X defaultData_;
    vector<X> data_;
    //無効値
    const M defaultLazy_;
    vector<M> lazy_;
public:
    SegTreeLazyProportional(int n_, FX query_value, FA merge_data_and_lazy, FM updateLazy, FP evaluateLazyLength, X defaultData, M defaultLazy)
        : n(), query_Value_(query_value), merge_data_and_lazy_(merge_data_and_lazy),
        updateLazy_(updateLazy),
        evaluateLazyLength_(evaluateLazyLength),
        defaultData_(defaultData),
        defaultLazy_(defaultLazy),
        data_(n_ * 4, defaultData_), lazy_(n_ * 4, defaultLazy_) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }

    void set(int i, X x) { data_[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) data_[k] = query_Value_(data_[2 * k + 1], data_[2 * k + 2]);
    }
    //[a,b)
    void update(int a, int b, M x) { update(a, b, x, 0, 0, n); }
    //[a,b)
    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }

private:
    void eval(int k, int len) {
        if (lazy_[k] == defaultLazy_) return;  // 更新するものが無ければ終了
        if (k < n - 1) {            // 葉でなければ子に伝搬
            lazy_[k * 2 + 1] = updateLazy_(lazy_[k * 2 + 1], lazy_[k]);
            lazy_[k * 2 + 2] = updateLazy_(lazy_[k * 2 + 2], lazy_[k]);
        }
        // 自身を更新
        data_[k] = merge_data_and_lazy_(data_[k], evaluateLazyLength_(lazy_[k], len));
        lazy_[k] = defaultLazy_;
    }

    void update(int a, int b, M x, int k, int l, int r) {
        eval(k, r - l);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy_[k] = updateLazy_(lazy_[k], x);
            eval(k, r - l);
        }
        else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            data_[k] = query_Value_(data_[k * 2 + 1], data_[k * 2 + 2]);
        }
    }

    X query_sub(int a, int b, int k, int l, int r) {
        eval(k, r - l);
        if (r <= a || b <= l) {  // 完全に外側の時
            return defaultData_;
        }
        else if (a <= l && r <= b) {  // 完全に内側の時
            return data_[k];
        }
        else {  // 一部区間が被る時
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return query_Value_(vl, vr);
        }
    }
};

ll mpow(ll x, ll n, ll m) {
    ll ans = 1; x %= m;
    while (n != 0) {
        if (n & 1) ans = ans * x % m;
        x = x * x % m;
        n = n >> 1;
    }
    return ans;
}

SegTreeLazyProportional<ll, ll> RangeSetQueryMin(int n) {
    auto queryValue = [=](ll left, ll right) -> ll { return min(left, right); };
    auto updateValue = [=](ll old, ll next) -> ll { return min(old, next); };
    auto merge = [=](ll source, ll lazyValue) -> ll { return min(source, lazyValue); };
    auto evaluate_lazy_length = [=](ll lazyValue, ll length) -> ll { return lazyValue; };
    ll defaultValue_ = 0;
    SegTreeLazyProportional<ll, ll> rmq(n, queryValue, merge, updateValue, evaluate_lazy_length,
        std::numeric_limits<ll>::max(), 1e15);
    return rmq;
}

ll lpow(ll seed, int n) {
    ll c = 1;
    for (int i = 0; i < n; i++) {
        c *= seed;
    }
    return c;
}

ll naive(ll n) {
    ll two = 0;
    ll five = 0;
    while (n > 0) {
        ll c = n;
        while (c % 2 == 0) {
            c /= 2;
            two++;
        }
        while (c % 5 == 0) {
            c /= 5;
            five++;
        }
        n -= 2;
    }
    return min(two, five);
}

ll fast(ll n) {
    ll sum = 0;
    for (int i = 0; 10 * lpow(5, i) <= n; i++) {
        auto d = 10 *lpow(5, i);
        sum += n / d;    
    }
    return sum;
}

int main() {
	ll n;
	cin >> n;
    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll sum = fast(n);
    cout << sum << endl;
	return 0;
}
