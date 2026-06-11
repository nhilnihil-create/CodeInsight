#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n,m;cin>>n>>m;
    int h[n];rep(i,n)cin>>h[i];
    int t[n];rep(i,n)t[i]=1;
    
    rep(i,m){
        int a,b;cin>>a>>b;
        --a;--b;
        if(h[a]<h[b])t[a]=0;
        if(h[b]<h[a])t[b]=0;
        if(h[b]==h[a])t[a]=t[b]=0;
    }
    int ans = 0;
    rep(i,n)ans+=t[i];
    cout<<ans<<endl;
	return 0;
}