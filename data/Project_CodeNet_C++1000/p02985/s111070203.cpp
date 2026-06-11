#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,k,ans=1,mod=1000000007;
  cin >> n >> k;
  vector<vector<long>> aaa(n);
  vector<bool> bo(n,true);
  for(long i=0;i<n-1;i++) {
    long a,b;
    cin >> a >> b;
    aaa[a-1].push_back(b-1);
    aaa[b-1].push_back(a-1);
  }
  queue<long> q;
  queue<long> q1;
  queue<long> q2;
  q.push(0);
  q1.push(0);
  q2.push(0);
  bo[0]=false;
  while(q.size()!=0) {
    long x=q.front();
    long y=q1.front();
    long z=q2.front();
    ans=ans*max(0L,k-y-z)%mod;
    for(long i=0;i<aaa[x].size();i++) {
      if(bo[aaa[x][i]]) {
        bo[aaa[x][i]]=false;
        q.push(aaa[x][i]);
        q1.push(1);
        q2.push(y);
        y++;
      }
    }
    q.pop();
    q1.pop();
    q2.pop();
  }
  cout << ans << endl;
}