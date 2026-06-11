#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n,k,r,s,p;
    cin>>n>>k>>r>>s>>p;
    string t;
    cin>>t;
    bool lose[200010]={false};
    ll ans=0;
    for(int i=0;i<n;i++){
        if(i<n-k){
            if(lose[i]) continue;
            if(t[i]==t[i+k]) lose[i+k]=true;
            if(t[i]=='r') ans+=p;
            else if(t[i]=='s') ans+=r;
            else ans+=s;
        }
        else{
            if(lose[i]) continue;
            if(t[i]=='r') ans+=p;
            else if(t[i]=='s') ans+=r;
            else ans+=s;
        }
    }
    cout<<ans<<endl;
}