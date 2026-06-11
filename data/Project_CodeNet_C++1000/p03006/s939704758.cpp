
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 10000000;
typedef pair<int,int> P;
typedef long long ll;
/*
*/

int main() {
  int N;
  cin >> N;
  vector<pair<ll,ll>> T(N);
  rep(i,N){
    cin >> T[i].first;
    cin >> T[i].second;
  }
  vector<pair<ll,ll>> pq;//異なる二点のx,y座標の差のペア列
  for(int i = 0;i<N;i++){
    for(int j = i+1;j<N;j++){
      pq.push_back(make_pair(T[i].first-T[j].first,T[i].second-T[j].second));
    }
  }
  /*for(int i = 0;i<pq.size();i++){
    cout << pq[i].first << " " << pq[i].second << endl;
  }*/

  
  ll cm = 0;
  for(int i = 0;i<pq.size();i++){
    ll count = 1;
    for(int j = 0;j<pq.size();j++){
      if(i == j) continue;
      if((pq[i].first == pq[j].first && pq[i].second == pq[j].second)
       || (pq[i].first == -pq[j].first && pq[i].second == -pq[j].second)) count++;
    }
    cm = max(cm,count);
  }
  cout << N-cm << endl;
}