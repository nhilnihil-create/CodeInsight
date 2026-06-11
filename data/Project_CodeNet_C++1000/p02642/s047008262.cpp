#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
using namespace std;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)1e9+7;
bool divid[1000006];
int freq[1000006];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,ans=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i],freq[v[i]]++;
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=0;i<v.size();i++)
        for(int j=v[i]+v[i];j<=1000000;j+=v[i])
            divid[j]=1;
    for(int i=0;i<v.size();i++)
        ans+=(freq[v[i]]==1&&divid[v[i]]==0);
    cout<<ans;
    return 0;
}
