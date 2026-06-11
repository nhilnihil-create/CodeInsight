#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string s;
    int k;
    cin>>s>>k;
    int n=s.size();
    s=s+s;
    int cnt1=0,cnt2=0;
    bool same=true;
    rep(i,n-1)if(s[i]!=s[i+1])same=false;
    rep(i,n-1){
        if(s[i]==s[i+1]){
            s[i+1]='.';
            cnt1++;
        }
    }
    for(int i=n-1; i<2*n-1; ++i){
        if(s[i]==s[i+1]){
            s[i+1]='.';
            cnt2++;
        }
    }
    if(!same)cout<<(ll)cnt2*(k-1)+cnt1<<endl;
    else cout<<(ll)n*k/2<<endl;
    return 0;
}