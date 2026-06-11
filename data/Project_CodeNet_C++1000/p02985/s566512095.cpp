#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

vector<ll> to[100010];

int main(){
    ll n,k;cin>>n>>k;
    rep(i,0,n-1){
        ll a,b;cin>>a>>b;
        a--;b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    queue<ll> q;
    q.push(0);
    vector<ll> oya(n,-1);
    vector<ll> col(n,-1);
    ll K=k-1;
    col[0]=k;
    while(!q.empty()){
        ll now=q.front();
        q.pop();
        ll nK=k-2;
        for(auto nx:to[now]){
           if(col[nx]!=-1)continue;
           if(now==0){
               oya[nx]=now;
               col[nx]=K;
               K--;
           }
           else{
               oya[nx]=now;
               col[nx]=nK;
               nK--;
           }
           q.push(nx);
        }
    }
    ll an=1;
    rep(i,0,n){
        an*=col[i];
        an%=1000000007;
    }
    cout<<an<<endl;
}

    







