#include <bits/stdc++.h>
using namespace std;

#define FLASH ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vpp vector<pair< int, int > >  
#define pll pair<int , int >
#define ppll pair < pll , pll >
#define debug(n1) cout << n1 << endl
#define len(a) ((int) (a).size())
#define endl "\n"

int32_t main()
{
    FLASH;
    int n,x,i;
    cin>>n;
    pll arr[n+1];
    for(i=1;i<=n;i++)
    {
       cin>>x;
       arr[i] = mp(x,i);
    }
    sort(arr+1,arr+n+1);
    for(int j=1;j<=n;j++)
    {
     cout<<arr[j].second<<" ";
    }
 
}