#include<iostream>
#include <queue>
using namespace std;
int main(){
  int i,n,m,a;
  cin >> n >> m;
  priority_queue<int> que; // 昇順
  for(i=0;i<n;i++){
    cin >> a;
    que.push(a);
  }
  for(i=0;i<m;i++){
    int x=que.top();
    que.pop();
    x=x/2;
    que.push(x);
  }
  long long ans=0;
  for(i=0;i<n;i++){
    int x=que.top();
    que.pop();
    ans+=x;
  }
  cout << ans << endl;
  return 0;
}