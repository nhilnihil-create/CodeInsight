#include<bits/stdc++.h>

using namespace std;

#define TC ll t; cin >> t; while(t--)
typedef long long ll;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,k;
    cin >> n >> k;
    n%=k;
    cout << min(n,k-n) << endl;
    return 0;
}
