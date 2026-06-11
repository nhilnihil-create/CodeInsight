#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
#define f first
#define s second
using namespace std;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)1e9+7;
const double eps=1e-9;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,sum=0,mn=INF;
    cin>>n;
    vector<int> v(n);
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++)
        cin>>v[i],sum+=abs(v[i]),mn=min(mn,v[i]);
    sort(v.begin(),v.end());
    for(int i=1;i<n-1;i++){
        if(v[i]>=0)
        ans.push_back({v[0],v[i]}),v[0]-=v[i];
        else
        ans.push_back({v[n-1],v[i]}),v[n-1]-=v[i];
    }
    ans.push_back({v[n-1],v[0]}),v[n-1]-=v[0];
    cout<<v[n-1]<<"\n";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].f<<" "<<ans[i].s<<"\n";
    return 0;
}
