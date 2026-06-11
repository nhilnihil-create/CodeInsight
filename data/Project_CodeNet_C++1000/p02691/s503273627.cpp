#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &i:v)
        cin>>i;
    map<int,int>mp;
    vector<int>sum(n),diff(n);
    for(int i=0;i<n;i++){
        sum[i]=v[i]+i+1;
        mp[sum[i]]++;
        diff[i]=i+1-v[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=mp[diff[i]];
    }
    cout<<ans<<endl;
}