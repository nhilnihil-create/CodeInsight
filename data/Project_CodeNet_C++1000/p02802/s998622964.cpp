#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> p(m);
    vector<string> s(m);
    vector<int> cnt(1000005,0);
    vector<int> ans(1000005,0);
    vector<int> num(1000005,0);
    rep(i,m) cin>>p[i]>>s[i];
    
    int i=0;
    rep(i,m){
        if(s[i]=="WA") cnt[p[i]]++;
        else if(s[i]=="AC"){
            if(num[p[i]]==0){
                ans[p[i]]+=cnt[p[i]];
                num[p[i]]++;
            }
        }
    }
    
    cout<<accumulate(num.begin(),num.end(),0)<<" "<<accumulate(ans.begin(),ans.end(),0);
    return 0;
}