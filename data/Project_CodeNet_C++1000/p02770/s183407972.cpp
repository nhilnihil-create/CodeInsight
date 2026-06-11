#include <bits/stdc++.h>
#include <stdio.h>


using namespace std;
#define ull unsigned long long
#define si short int
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define piii pair<pair<int, int>, int>
#define all(vec) vec.begin(), vec.end()
#define piiii pair<pair<int, int>, pair<int, int>>
#define fr(a, from, c) for(int a=(from); (a)<(c); (a)++)

/*-----------------------------------------------------SegTree---------------------------------------------*/
int mxn11 = (int) (1e1 + 1);
ll inf = 0;
vector<ll> t1(4 * mxn11 + 1, (ll) 0);
vector<ll> t2(4 * mxn11 + 1, (ll) 0);
vector<ll> t3(4 * mxn11 + 1, (ll) 0);

ll getmax(int v, int vl, int vr, int l, int r) {
    if (l > r) return inf;
    if (vl == l && vr == r) {
        return t1[v]/* + tAdd[v]*/;
    }
    int tmp = (vl + vr) >> 1;
    // push(v);
    ll a = getmax(2 * v, vl, tmp, l, min(tmp, r));
    ll b = getmax(2 * v + 1, tmp + 1, vr, max(tmp + 1, l), r);
    return max(a, b);
}

void update(int v, int vl, int vr, int l, ll cnt) {
    if (vl == vr) {
        t1[v] = cnt;
        return;
    }
    int tmp = (vl + vr) >> 1;
    //push(v);
    if (l <= tmp)
        update(2 * v, vl, tmp, l, cnt);
    else
        update(2 * v + 1, tmp + 1, vr, l, cnt);
    t1[v] = max(t1[2 * v], t1[2 * v + 1]);
}
/*-----------------------------------------------------SegTree---------------------------------------------*/

/*-----------------------------------------------------MATH------------------------------------------------*/
inline ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

inline int pwm(ll xx, ll pow, int MD) {
    if (pow < 0) { pow = pow % (MD - 1) + MD - 1; }
    ll mlt = 1;
    while (pow) {
        if (pow & 1) {
            mlt *= xx;
            mlt %= MD;
        }
        xx *= xx;
        pow >>= 1;
        xx %= MD;
    }
    return (int) mlt;
}

inline ll gcdex(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll xx, yy;
    ll gc = gcdex(b, a % b, yy, xx);
    x = xx;
    y = yy - (a / b) * xx;
    return gc;
}

inline int inv(ll r, int _mod) { return pwm(r % _mod, _mod - 2, _mod); }

inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? (
            (y < hpow) ? 0 : 3
    ) : (
                      (y < hpow) ? 1 : 2
              );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

/*-----------------------------------------------------MATH------------------------------------------------*/
ll mod=1e9+7;
vector<ll> fact;
vector<ll> invfact;
void prec(int n){
    fact.resize(n+1);
    invfact.resize(n+1);
    fact[0]=1;
    for(ll i=1;i<=n;i++){
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
    }
    for(int i=0;i<n+1;i++){
        invfact[i]=inv(fact[i], mod);
    }
}
ll cnk(int k, int n){
    ll ans=1;
    ans=fact[n]*invfact[k];
    ans%=mod;
    ans*=invfact[n-k];
    ans%=mod;
    return ans;
}
/*
4 10
4 5 5 5
3 1 5*/
vector<ll> d;
void solve() {
    ll k,q;
    cin>>k>>q;
    d.resize(k);
    for(int i=0;i<k;i++) {
        cin >> d[i];
    }
    for(int i=0;i<q;i++){
        ll n,x,m;
        cin>>n>>x>>m;
        x%=m;
        ll summ=x;
        for(int j=0;j<k;j++){
            ll sh=d[j]%m;
            if(sh==0) sh=m;
            summ+=(sh)*max((n-j-1+k-1)/k, 0ll);
           // cout<<j<<" "<<(n-j-1+k-1)/k<<endl;
        }
      //  cout<<"summ: "<<summ<<endl;
        ll all=n-1-(summ)/m;
        cout<<all<<endl;
    }
}

int main() {
    /*ios::sync_with_stdio(false);
    cin.tie(nullptr);*/
    //freopen("C:\\Users\\Maximus\\CLionProjects\\Codeforces\\BestTeam\\output.txt", "r", stdin);
    //freopen("C:\\Users\\Maximus\\CLionProjects\\Codeforces\\BestTeam\\output.txt", "w", stdout);
    unsigned int beg_time = clock();

    int n=1;
    for (int i = 0; i < n; i++) solve();


    unsigned int end_time = clock();
    //cout<<endl<<endl<<end_time-beg_time;

    return 0;
}