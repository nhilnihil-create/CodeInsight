#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll DPX[100100];
ll DPY[100100];

int main(){
    string L;
    cin >> L;
    ll N = L.size();

    DPX[0] = 1;

    REP(i,N){
        char c = L[i];
        if(c == '1'){
            //1
            DPX[i+1] += DPX[i] * 2;

            //0, 1
            DPY[i+1] += DPY[i] * 3;
            //0
            DPY[i+1] += DPX[i];
        }
        else{
            //0
            DPX[i+1] += DPX[i];

            //0, 1
            DPY[i+1] += DPY[i] * 3;
        }

        DPX[i+1] %= MOD;
        DPY[i+1] %= MOD;
    }

    ll ans = DPX[N] + DPY[N];
    cout << ans % MOD << endl;
    
    return 0;
}
