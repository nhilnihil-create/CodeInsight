#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef tuple<int,int,int> tii;

#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  vector<ll> A;
  A.push_back(0);
  ll K; cin >> K;
  if(K<10){
    cout << K << endl;
    return 0;
  }
  int cnt = 0;
  queue<pii> que;
  for(int i=1;i<=9;i++){
    que.push(make_pair(i,i));
    A.push_back(i);
    cnt++;
  }
  while(cnt<K){
    pii P = que.front(); que.pop();
    ll x = P.first,y = P.second;
    for(int i=-1;i<=1;i++){
      ll nx = x + i;
      ll ny = 10*y + nx;
      if(nx>=0&&nx<=9){
        que.push(make_pair(nx,ny));
        A.push_back(ny);
        cnt++;
      }
    }  
    
  }
  cout << A[K] << endl;
}