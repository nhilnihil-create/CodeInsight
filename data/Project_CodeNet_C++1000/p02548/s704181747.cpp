#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x)  (int)x.size()
#define en     '\n'
#define sp     ' '
#define in(v)  for(auto &a: v)cin >> a;
#define out(v) for(auto &a: v)cout << a << sp;cout << en;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n, ans = 0, i, j;cin >> n;
    for(i = 1;i <= n;i++){
        for(j = 1;j <= n;j++){
            if(i * j < n)ans++;
            else break;
        }
    }
    cout << ans << en;
    return 0;
}
