#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;
template<class T>
using MaxHeap = std::priority_queue<T>;

int main(){
  cout << setprecision(10);
  int N,M; cin >> N >> M;

  MaxHeap<ll> h;
  for(int i = 0; i < N; i++){
    ll tmp; cin >> tmp;
    h.push(tmp);
  }
  
  while(M>0){
    ll now = h.top();
    h.pop();
    now /= 2;
    h.push(now);
    M--;
  }
  ll ans = 0;
  while(!h.empty()){
    ll now = h.top();
    ans += now;
    h.pop();
  }
  cout << ans << endl;


}
