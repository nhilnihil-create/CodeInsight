#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll now = 0;
    ll ans = 1;
    for(int i = 0; i < n * 2; i++){
        if(now % 2){
            if(s[i] == 'W') now++;
            else{
                ans = ans * now % MOD;
                now--;
            }
        }
        else{
            if(s[i] == 'B') now++;
            else{
                ans = ans * now % MOD;
                now--;
            }
        }
    }
    ll f = 1;
    for(ll i = 1; i <= n; i++) f = f * i % MOD;
    if(now == 0) cout << ans * f % MOD << endl;
    else cout << 0 << endl;
}