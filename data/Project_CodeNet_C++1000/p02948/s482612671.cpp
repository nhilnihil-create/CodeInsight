#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

bool gt(pii x, pii y){
  return x.first > y.first;
}

int main(){
  cout << setprecision(10);
  priority_queue<int> q;

  int N,M;
  cin >> N >> M;

  vector<pii> v(N);
  for(int i = 0; i < N; i++){
    int tmp1,tmp2;
    cin >> tmp1 >> tmp2;
    v.at(i) = make_pair(tmp1, tmp2);
  }

  sort(v.rbegin(), v.rend(), gt);
  // cerr << v.at(0).first << endl;
  ll ans = 0;
  int index = 0;
  for(int i = 1; i <= M; i++){
    while(index < N && v[index].first <= i ){
      q.push(v[index].second);
      index++;
    }
    if(!q.empty()){
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
}
