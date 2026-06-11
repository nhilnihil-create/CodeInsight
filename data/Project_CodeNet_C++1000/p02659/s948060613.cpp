#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    ll A;
    string B;
    cin >> A >> B;
    ll C = 0;
    rep(i,B.size()) {
        if (B[i]=='.') continue;
        C = C*10 + (ll) B[i] - '0';
    }
    ll ans = A*C;
    ans /=100;

    cout << ans << endl;
}
