#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main()
{
    ll n,k,cnt=0,ans,a;
 
    cin >> n >> k;
 
    a = n%k;
    ans = min(a,k-a);
 
    cout << ans << endl;
    return 0;
 
}