#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int ans=0;
    string s,t;
    cin>>s>>t;
    rep(i,s.size()){
        if(s[i]!=t[i])ans+=1;
    }
    cout<<ans<<endl;
}