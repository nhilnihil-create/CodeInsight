#include<bits/stdc++.h>
#define int long long
/* #define double long double */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)

signed main(){
    ll k;
    cin >> k;
    ll a = 7;
    for(int i = 1; i <= k; i++){
        a %= k;
        if(a % k == 0){
            cout << i << endl;
            return 0;
        }
        a = 10*a + 7;
    }
    cout << -1 << endl;
}