 /* while(!cin.eof()) */
 
#include<bits/stdc++.h>
using namespace std; 
#define int long long 
#define mod 998244353
#define endl '\n'
#define MAXI (int)(3e17+10)
#define N 1000005


// Driver code to test above functions
int32_t main()
{
  
     
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, ans = 0;
    cin >> n;
    map<int, int> mp;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;

        ans += mp[i-x];

        mp[i+x]++;
    }

    cout << ans;

    return 0;

} 
