#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int N;
  cin >> N;
  map <string, int> vote;
  int MAX = 0;
  rep(i,N){
    string S;
    cin >> S;
    if(vote.count(S)){
      vote[S] += 1;
    }
    else{
      vote[S] += 1;
    }
    MAX = max(vote[S],MAX);
  }
  for(auto p : vote){
    auto k = p.first;
    auto v = p.second;
    if(v == MAX){
      cout << k << endl;
    }
  }
  return 0;
}

