#include<bits/stdc++.h>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<ll>a(n+2),b(n+2),now(n+2);
    bool f=1;
    rep(i,n)cin>>a[i+1];
    rep(i,n)cin>>b[i+1];
    a[0]=a[n];
    a[n+1]=a[1];
    b[0]=b[n];
    b[n+1]=b[1];
    rep(i,n+2){
        now[i]=b[i];
    }
    queue<ll>q;
    REP(i,1,n+1){
        if(b[i]==a[i])continue;
        if(b[i-1]+b[i+1]<=b[i]-a[i]){
            q.push(i);
        }
    }
    ll cnt=0;
    while(!q.empty()){
        ll k=q.front();
        q.pop();
        ll d=now[k+1]+now[k-1];
        ll dd=now[k];
        dd-=a[k];
        cnt+=dd/d;
        dd%=d;
        dd+=a[k];
        now[k]=dd;
        if(k==1)now[n+1]=now[k];
        if(k==n)now[0]=now[k];
        ll i=k+1;
      if(i==n+1)i=1;
        if(now[i]==a[i]);
        else if(now[i-1]+now[i+1]<=now[i]-a[i]){
            q.push(i);
        }
        i=k-1;
      if(i==0)i=n;
        if(now[i]==a[i]);
        else if(now[i-1]+now[i+1]<=now[i]-a[i]){
            q.push(i);
        }
        //rep(j,n+2)cout<<now[j]<<' ';
        //cout<<endl;
    }
    REP(i,1,n+1){
        if(a[i]!=now[i])f=0;
        //cout<<a[i]<<' '<<now[i]<<endl;
    }
    cout<<(f?cnt:-1)<<endl;
}