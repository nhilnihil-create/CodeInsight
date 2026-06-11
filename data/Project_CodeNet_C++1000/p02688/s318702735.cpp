#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,int>mp;
    int n,k;
    cin>>n>>k;
    while(k--){
        int d;
        cin>>d;
        for(int i=0;i<d;i++)
        {
            int a;
            cin>>a;
            mp[a]=d;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(mp[i]==0)
        {
            ans+=1;
        }
    cout<<ans<<endl;
}