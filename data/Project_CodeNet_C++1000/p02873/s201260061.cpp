#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int>ans(n+1,0);
    rep(i,n){
        if(s[i]=='<'){
            if(ans[i]>=ans[i+1])ans[i+1]=ans[i]+1;
        }
    }
    for(int i=n-1; i>=0; --i){
        if(s[i]=='>'){
            if(ans[i]<=ans[i+1])ans[i]=ans[i+1]+1;
        }
    }
    ll sum=0;
    rep(i,n+1){
        sum+=ans[i];
    }
    cout<<sum<<endl;
    return 0;
}