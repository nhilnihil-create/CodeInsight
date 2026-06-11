#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,m;	cin >> n >> m;
  priority_queue<long long, vector<long long>, less<long long>> a;
  for(long long i=0;i<n;i++){
    long long x;	cin >> x;
    a.push(x);
  }
  
  for(long long i=0;i<m;i++){
    long long x=a.top();
    a.pop();
    a.push(x/2);
  }
  long long ans=0;
  while(!a.empty()){
    ans+=a.top();
    a.pop();
  }
  cout << ans;
}