#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;



int main(){
  ll N;
  cin >> N;
  vector<vector<ll>> A(N, vector<ll>(N-1, 0));
  for(ll i=0;i<N;i++){
   for(ll j=0;j<N-1;j++){
     cin>>A[i][j];
     A[i][j]--;
   ;}
  ;}
  //次やりたい試合
  vector<ll> mark(N,0);
  ll ans=0;
  vector<bool> ful(N,0);
  ll full=0;
  queue<ll> mati;
  for(ll i=0;i<N;i++){
    mati.push(i);
  ;}
  while(1){
    //その日試合するなら１
    vector<ll> check(N,0);
    //試合できれば
    bool s=0;
    ll n=mati.size();
    for(ll i=0;i<n;i++){
        ll x=mati.front();
        mati.pop();
      //xが試合待ちかどうか
      if(check[x]||ful[x])continue;
      ll y=A[x][mark[x]];
      if(x==y)continue;
      //yが試合待ちかどうか
      if(check[y]||ful[y])continue;
      if(A[y][mark[y]]==x){
        mark[x]++;mark[y]++;
        if(mark[x]==N-1){ful[x]=1;full++;}
        if(mark[y]==N-1){ful[y]=1;full++;}
        check[x]=1;check[y]=1;
        mati.push(x);
        mati.push(y);
        s=1;
      }
    ;}
    if(s){
      ans++;
      if(full==N)break;
    }
    //試合できない
    else {
      cout<<-1<<endl; return 0;
    }

  }


  cout<<ans<<endl;
    return 0;
}
