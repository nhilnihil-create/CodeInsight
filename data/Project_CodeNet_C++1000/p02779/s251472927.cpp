#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    ll i, testcase, n, b, j  ;
    map<ll,ll>mp;
    cin >> n ;
    ll a[n];
    for(i=0; i<n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    if(mp.size()==n)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
