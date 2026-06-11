#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  int N,K;
  cin>>N>>K;
  if(K>(N-1)*(N-2)/2) cout<<-1<<endl;
  else{
    int t = 0;
    vector<vector<int>> v(K,vector<int>(2));
    for(int i = 1;i < N-1; i++){
      for(int j = i+1; j < N; j++){
        if(t==K) break;
        v[t]={i,j};
        t++;
      }
      if(t==K)break;
    }
    int cnt = 0;
    cout<<N*(N-1)/2-K<<endl;
    for(int i = 0; i < N-1;i++){
      for(int j = i+1; j<N; j++){
        if(cnt<K&&v[cnt][0]==i&&v[cnt][1]==j){
          cnt++;
          continue;
        }
        cout<<i+1<<" "<<j+1<<endl;
      }
    }
  }
}