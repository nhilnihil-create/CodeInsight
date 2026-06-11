#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin() , v.end()
#define w(x) cout << (#x) << " is " << x << "\n" ;
#define fast ios_base::sync_with_stdio(false) , cin.tie(0) ;
int main()
{
    fast ;
    int k, x ,n , i;
    vector<int>v ;
    cin >> n ;
    for(i = 0 ; i < n ; i++)
    {
        cin >> x ;
        v.pb(x) ;
    }
    sort(all(v)) ;
    n = n/2 ;
    cout << v[n] - v[n-1] << "\n" ;
    return 0;
}