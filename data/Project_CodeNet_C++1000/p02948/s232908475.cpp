#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
template<class T>
using MaxHeap = std::priority_queue<T>;

int main(){
  cout << setprecision(10);

  MaxHeap<ll> pq;
  int N, M; cin >> N >> M;

  vector<pair<ll,ll>> v(N);

  for(int i = 0; i < N; i++){
    ll x,y; cin >> x >> y;
    v[i] = make_pair(x,y);
  }

  sort(v.begin(), v.end());

  int index = 0;
  ll ans = 0;
  for(int i = 0; i <= M; i++){
    // i日以下の仕事をpqに追加する
    while(v[index].first <= i && index <= N-1){
      pq.push(v[index].second);
      index++;
    }

    if(pq.empty()) continue;

    ans += pq.top();
    // cerr << i << " " << pq.top() << endl;
    pq.pop();
  }
  cout << ans << endl;

}
