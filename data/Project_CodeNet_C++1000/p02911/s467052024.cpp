#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

void solve()
{
    int n,k,q;cin>>n>>k>>q;
    vector<int>arr(n+1,k-q);
    while(q--)
    {
        int l;cin>>l;
        arr[l]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(arr[i]>0)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
}
int32_t main()
{
         rapido;
         int t;
         //cin>>t;
         t=1;
         while(t--)
         solve();
}