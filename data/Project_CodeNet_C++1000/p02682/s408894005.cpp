#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int ans = (a < k ? a : k); k -= a;
    if(k > 0) k-= b;
    if(k > 0) ans -= (c < k ? c : k); 
    cout << ans << "\n";
    return 0;
}

