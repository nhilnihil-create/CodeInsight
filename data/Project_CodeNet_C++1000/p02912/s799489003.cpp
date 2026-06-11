#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N,M;
  cin>>N>>M;
  priority_queue<int>q;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    q.push(a);
  }
  for(int i=0;i<M;i++){
    int a=q.top();q.pop();
    q.push(a/2);
  }
  int64_t ans=0;
  for(int i=0;i<N;i++){
    ans+=q.top();q.pop();
  }
  cout<<ans<<endl;
  return 0;
}