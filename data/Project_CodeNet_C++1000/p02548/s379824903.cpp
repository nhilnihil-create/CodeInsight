#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
typedef long long ll;
const ll mod=pow(10,9)+7;
int main()
{
    ll n;
    cin >> n;

    ll ans = 0;

    for(int i=1; i<n; i++){
        ans += (n-1)/i;
    }

    cout << ans << endl;

    return 0;
}