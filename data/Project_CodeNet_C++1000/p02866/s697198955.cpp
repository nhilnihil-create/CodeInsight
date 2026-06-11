#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=998244353;
signed main(){
    int n,d[100000];
    map<int,int>mp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i];
        mp[d[i]]++;
    }
    if(d[0]!=0){
        cout<<0<<endl;
        return 0;
    }
    int ans=1;
    for(int i=1;i<n;i++)
        (ans*=mp[d[i]-1])%=mod;
    cout<<ans<<endl;
}
