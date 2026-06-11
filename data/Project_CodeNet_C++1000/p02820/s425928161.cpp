#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N,K;
    cin >> N >> K;
    int R,S,P;
    cin >> R >> S >> P;
    string T;
    cin >> T;
    ll ans = 0;
    string U;
    rep(i,N) {
        if (i<K) {
            if (T[i]=='r') ans+=P, U.push_back('p');
            else if (T[i]=='s') ans+=R, U.push_back('r');
            else ans+=S, U.push_back('s');
        }
        else {
            if (T[i]=='r') {
                if (U[i-K]=='p') U.push_back('w');
                else ans+=P, U.push_back('p');
            }
            else if (T[i]=='s') {
                if (U[i-K]=='r') U.push_back('w');
                else ans+=R, U.push_back('r');
            }
            else {
                if (U[i-K]=='s') U.push_back('w');
                else ans+=S, U.push_back('s');
            }
        }
    }
    cout << ans << endl;
}
