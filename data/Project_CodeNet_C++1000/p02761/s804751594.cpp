#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<int> s(m);
    vector<int> c(m);
    
    rep(i,m) cin>>s[i]>>c[i];
    
    vector<int> ans(n,0);
    
    if(n>1 && m==0){
        cout<<pow(10,n-1)<<endl;
        return 0;
    }
    
    rep(i,m){
        if(n!=1 && s[i]==1 && c[i]==0){
            cout<<-1<<endl;
            return 0;
        }
    }
    
    rep(i,m-1){
        for(int j=i+1;j<m;j++)
            if(s[i]==s[j]){
                if(c[i]!=c[j]){
                    cout<<-1<<endl;
                    return 0;
                }
            }
    }
    
    rep(i,m){
        if(s[i]!=1) ans[0]=1;
    }
    
    rep(i,m) ans[s[i]-1]=c[i];
    rep(i,n) cout<<ans[i];
    
    return 0;    
}