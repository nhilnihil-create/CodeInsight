#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

static const int INTINF = (2147483647 >> 1); // 10^9 + 5000
static const ll LLINF = (9223372036854775807 >> 1);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;

namespace Kunitaka{
    template<
        typename TYPE,
        std::size_t SIZE
    >
    std::size_t array_length(const TYPE (&array)[SIZE])
    {
        return SIZE;
    }
}
using namespace Kunitaka;
namespace Printer{
    void br(){
        cout << endl;
    }

    void loop_cnt(int i){
        cout << "i = " << i << endl;
    }

    void loop_cnt(int i, int j){
        cout << "i = " << i << ", " << "j = " << j << endl;
    }

    template<class T>
    void print(T x){
        cout << x << endl;
    }

    template<class T, class S>
    void print(T x, S y){
        cout << x << "," << y << endl;
    }

    template<class T, class S, class U>
    void print(T x, S y, U z){
        cout << x << "," << y << "," << z << endl;
    }

    template<class T, class S>
    void print(pair<T, S> p){
        cout << p.first << ", " << p.second << endl;
    }

    template<
        typename TYPE,
        std::size_t SIZE
    >
    void print(const TYPE (&array)[SIZE]){
        int lim = array_length(array);
        for(int i=0; i<lim; i++){
            if(i) cout << " ";
            cout << array[i];
        }
        cout << endl;
    }

    template<class S>
    void print(vector<S> v){
        for(int i=0; i<v.size(); i++){
            if(i) cout << " ";
            cout<< v[i];
        }
        cout << endl;
    }

    template<class S>
    void print(vector<vector<S> > vv){
        for(int i=0; i<vv.size(); i++){
            for(int j=0; j<vv[i].size(); j++){
                if(j) cout << " ";
                cout << vv[i][j];
            }
            cout << endl;
        }
    }

    void yesno(bool x){
        if(x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
};
using namespace Printer;

class SegmentTree{
    private:
        const ll INTINF = 2147483647 >> 1; // 2147483647 >> 1
        static const ll MAX_N = 1 << 17;
        ll n, dat[2 * MAX_N -1];
        bool isMax;

    public:
        void init(ll n_){
            if(INTINF == 0) isMax = true;
            else isMax = false;
            n = 1;
            while(n < n_) n*= 2;
            for(ll i=0; i< 2*n-1; i++) dat[i] = INTINF;
        }

        // k番目の値(0-indexed)をaに変更
        void update(ll k, ll a){
            k += n-1;
            dat[k] = a;
            while(k > 0){
                k = (k-1) / 2;
                if(isMax) dat[k] = max(dat[k*2 + 1], dat[k * 2 + 2]);
                else dat[k] = min(dat[k*2 + 1], dat[k * 2 + 2]);
            }
        }

        //[a, b)の最小値を求める
        ll query(ll a, ll b, ll k = 0, ll l = 0, ll r = -1){
            if(r < 0) r = n;
            if(r <= a || b <= l) return INTINF;

            if(a <= l && r <= b) return dat[k];
            else{
                ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
                ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
                if(isMax) return max(vl, vr);
                return min(vl, vr);
            }
        }

        // 全てのノードの値を表示
        void debug(){
            for(ll i=0; i<n * 2 -1; i++){
                if(i == n-1) cout << "leaf->" << endl;
                cout << dat[i] << endl;
            }
        }
};

int main(int argc, const char * argv[]) {
    //提出時、消す----//
    //--------------//


    // input
    cout << fixed << setprecision(10);
    int N, M; cin >> N >> M;
    string str; cin >> str;
    vector<int> dp(N+1, 0);
    int len = 0;
    rep(i, str.size()){
        if(str[i] == '1'){
            len++;
            dp[i] = INTINF;
            if(len >= M) {
                cout << -1 << endl;
                return 0;
            }
        }
        else{
            len = 0;
        }
    }

    ll ans = 0;
    dp[N] = 0;
    SegmentTree seg;
    seg.init(N+1);
    seg.update(N, 0);
    for(int i=N-1; i>=0; i--){
        if(str[i] == '1') continue;
        int l = i;
        int r = min(N, l + M);
        int mi = seg.query(l, r+1);
        seg.update(i, mi + 1);
        dp[i] = mi + 1;
    }

    vector<int> path;
    int bef = dp[0];
    int p = 0;
    rep(i, N+1){
        if(bef > dp[i]){
            path.push_back(p);
            p = 0;
            bef = dp[i];
        }
        p++;
    }

    // print(dp);
    print(path);
    
    return 0;
}
