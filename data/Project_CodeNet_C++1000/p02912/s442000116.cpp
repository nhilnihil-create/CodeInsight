#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int mod = 1e9+7;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int n,m;
  cin>>n>>m;
  int a;
  priority_queue<int> q;
  for(int i=0;i<n;i++) cin>>a,q.push(a);
  while(m--) {
    int price = q.top();
    q.pop();
    q.push(price>>1);
  }
  ull sum = 0;
  while(!q.empty())
    sum+=q.top(),q.pop();
  cout<<sum;
  cout<<"\n";
  return 0;
}