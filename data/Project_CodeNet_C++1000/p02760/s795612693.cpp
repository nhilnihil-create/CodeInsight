// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    ll v[3][3];
    ll t[3][3];
    rep(i,3){
        rep(j,3){
            t[i][j]=0;
        }
    }
    rep(i,3) cin>>v[i][0]>>v[i][1]>>v[i][2];
    cin>>n;
    ll w[n];
    rep(i,n) cin>>w[i];
    rep(j,n){
        rep(i,3){
        if(v[i][0]==w[j]) t[i][0]=1;
        if(v[i][1]==w[j]) t[i][1]=1;
        if(v[i][2]==w[j]) t[i][2]=1;
        if(v[0][i]==w[j]) t[0][i]=1;
        if(v[1][i]==w[j]) t[1][i]=1;
        if(v[2][i]==w[j]) t[2][i]=1;
        }
    }
    if(t[0][0]==1&&t[0][1]==1&&t[0][2]==1) f=1;
    if(t[1][0]==1&&t[1][1]==1&&t[1][2]==1) f=1;
    if(t[2][0]==1&&t[2][1]==1&&t[2][2]==1) f=1;
    if(t[0][0]==1&&t[1][0]==1&&t[2][0]==1) f=1;
    if(t[0][1]==1&&t[1][1]==1&&t[2][1]==1) f=1;
    if(t[0][2]==1&&t[1][2]==1&&t[2][2]==1) f=1;
    if(t[0][0]==1&&t[1][1]==1&&t[2][2]==1) f=1;
    if(t[2][0]==1&&t[1][1]==1&&t[0][2]==1) f=1;

    rep(i,3){
        rep(j,3){
           // cout<<t[i][j]<<" ";
        }
        //ln;
    }
    if(f==1)Yes;
    else No;

    return 0;
}
