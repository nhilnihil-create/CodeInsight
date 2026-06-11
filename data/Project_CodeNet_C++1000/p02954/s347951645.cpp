#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int>ans(n);
    int cnt=0;
    rep(i,n){
        if(s[i]=='R')cnt++;
        else{
            ans[i-1]+=(cnt+1)/2;
            ans[i]+=cnt/2;
            cnt=0;
        }
    }
    cnt=0;
    for(int i=n-1; i>=0; --i){
        if(s[i]=='L')cnt++;
        else{
            ans[i+1]+=(cnt+1)/2;
            ans[i]+=cnt/2;
            cnt=0;
        }
    }
    rep(i,n)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}