#include<bits/stdc++.h>
#define rep(i,n) for(i=0;i<(n);i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main(){
  int n,m;
  cin >> n >> m;
  int a,i;
  priority_queue<int> que;
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
      