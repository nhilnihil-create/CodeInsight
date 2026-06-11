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
    int N;
    cin >> N;
    int C[9][9] = {};
    int ans = 0;
    rep(i,N) {
        string s = to_string(i+1);
        rep(a,9) {
            string A;
            A = to_string(a+1);
            if (s[0]!=A[0]) continue;

            rep(b,9) {
                
                string B;
                B = to_string(b+1);
                if (s[0]==A[0] && s[s.size()-1]==B[0]) {
                    C[a][b]++;
                }
            }
        }
    }
    rep(a,9) {
        rep(b,9) {
            ans += C[a][b]*C[b][a];
        }
    }
    cout << ans <<endl;
}
