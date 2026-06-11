#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,m,p[100005],cnt[100005],x,ac=0,pen=0;
    string s;
    cin>>n>>m;
    rep(i,n+1){
        p[i]=0;
        cnt[i]=0;
    }
    rep(i,m){
        cin>>x>>s;
        if(s[0]=='W'&&p[x]==0){
            cnt[x]++;
        }
        if(s[0]=='A'&&p[x]==0){
            p[x]=1;
            ac++;
            pen+=cnt[x];
        }
    }
    cout<<ac<<" "<<pen;

}