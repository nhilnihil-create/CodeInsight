#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin >> N >> M;
  priority_queue<long long> p;
  for(int i=0; i<N; i++){
    long long a;
    cin >> a;
    p.push(a);
  }
  for(int i=0; i<M; i++){
    long long b;
    b = p.top();
    p.pop();
    b /= 2;
    p.push(b);
  }
  long long ans=0;
  for(int i=0; i<N; i++){
    ans += p.top();
    p.pop();
  }
  cout << ans << endl;
  return 0;
}
