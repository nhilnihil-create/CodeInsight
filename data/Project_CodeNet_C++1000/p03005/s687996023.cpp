#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
signed main()
{
    IOS
    int n,k; cin>>n>>k;
    if(k == 1)
    {
      cout<<0;
      return 0;
    }
    int diff = n-k;
    cout<<diff<<endl;
    return 0;
}