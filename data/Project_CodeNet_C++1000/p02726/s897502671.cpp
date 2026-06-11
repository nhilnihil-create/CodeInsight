#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}

const int INF=1001001001;

int main() {
  int N,X,Y;
  cin>>N>>X>>Y;
  X--;Y--;
  map<int,int>k;

  for(int i=0;i<N;i++){
    vector<int>dist(N,INF);
    queue<int>q;

    auto push=[&](int v,int d){
      if(dist[v]!=INF){return;}
      dist[v]=d;
      q.push(v);
    };
    push(i,0);
    while(!q.empty()){
      int v=q.front();q.pop();
      int d=dist[v];
      if(v-1>=0){push(v-1,d+1);}
      if(v+1<N){push(v+1,d+1);}
      if(v==X){push(Y,d+1);}//迂回は＋１より先に来るから更新されない
      if(v==Y){push(X,d+1);}
    }
    for(int i=0;i<N;i++){
      k[dist[i]]++;
    }
  }
  for(int i=1;i<N;i++){
    cout<<k[i]/2<<endl;
  }
  return 0;
}