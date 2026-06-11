#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N,K,S;
    cin >> N >> K >> S;

    if (S==1000000000) {
        rep(i,K) {
            cout << S << " ";
        }
        rep(i,N-K) {
            cout << 1 << " ";
        }
        cout << endl;
    }
    else {
        rep(i,K) {
            cout << S << " ";
        }
        rep(i,N-K) {
            cout << S+1 << " ";
        }
        cout << endl;
    }
}
