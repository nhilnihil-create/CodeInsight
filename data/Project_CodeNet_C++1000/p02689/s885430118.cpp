#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long ;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> h(n);
    rep(i,n) cin>>h[i];
    vector<int> data(n,1);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        if(h[a]>h[b]) data[b]=0;
        else if(h[a]<h[b]) data[a]=0;
        else{
            data[a]=0;
            data[b]=0;
        }
    }
    int ans=0;
    rep(i,n) ans+=data[i];
    cout<<ans;
}