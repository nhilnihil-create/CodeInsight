#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    long long wa[n+1];
    wa[0]=0;
    map<int,vector<int>>x;
    set<int>s;
    for(int i=1;i<=n;i++)wa[i]=wa[i-1]+a[i-1];
    for(int i=0;i<=n;i++){
        wa[i]=((wa[i]-i)%k+k)%k;
        x[wa[i]].push_back(i);
        s.insert(wa[i]);
    }
    long long ans=0;
    for(auto itr=s.begin();itr!=s.end();itr++){
        vector<int>v=x[*itr];
        for(int i=0;i<v.size();i++)ans+=lower_bound(v.begin(),v.end(),v[i]+k)-v.begin()-i-1;
    }
    cout<<ans<<endl;
    return 0;
}