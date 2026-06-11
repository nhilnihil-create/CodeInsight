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

ll dp[MAX+100][2];
string L;

// ll solve(int idx, bool tight){
//     if(idx == L.size()){
//         return 1;
//     }



//     int nowL = L[idx] - '0';
//     if(tight){
        
//         ll res = 0;
//         res += solve(idx+1, true) * 2;
//         res %= MOD;
//         res += solve(idx+1, false);
//         res %= MOD;
//         return res;
//     }
//     else{
//         return solve(idx+1, false) * 3 % MOD;
//     }
// }

int main(int argc, const char * argv[]) {
    //提出時、消す----//
    //--------------//


    // input
    cout << fixed << setprecision(10);
    cin >> L;

    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = 1;
    dp[0][1] = 2;
    rep2(i, 1, L.size()){
        int nowL = L[i] - '0';
        if(nowL == 0){
            dp[i][0] = dp[i-1][0] * 3 % MOD;
            dp[i][1] = dp[i-1][1] % MOD;
        }
        else{
            dp[i][0] = (dp[i-1][1] + dp[i-1][0] * 3) % MOD;
            dp[i][1] = dp[i-1][1] * 2 % MOD;
        }
    }

    print((dp[L.size()-1][0] + dp[L.size()-1][1]) % MOD);
    
    
    return 0;
}
