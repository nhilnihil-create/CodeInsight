#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;
typedef long long ll;

int main(){
  int N,M;
  cin >> N >> M;
  priority_queue<ll> que;
  for(int i=0;i<N;i++){
    ll a;
    cin >> a;
    que.push(a);
  }
  for(int j=0;j<M;j++){
    ll b = que.top()/2;
    que.pop();
    que.push(b);
  }
  ll sum=0;
  for(int i=0;i<N;i++){
    sum+=que.top();
    que.pop();
  }
  cout << sum << endl;
}
