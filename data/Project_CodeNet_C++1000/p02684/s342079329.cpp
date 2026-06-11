#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;


int main() {
  int64_t N,K;
  cin>>N>>K;
  vector<int>A(N+1);
  for(int i=1;i<=N;i++){
    cin>>A[i];
  }
  vector<int>num(N+1,-1);
  vector<int>q;
  int now=1;
  while(num[now]==-1){
    num[now]=q.size();
    q.push_back(now);
    now=A[now];
  }
  int nr=num[now];
  int r=q.size()-nr;
  if(K<nr){cout<<q[K]<<endl;return 0;}
  else{
    K-=nr;
    K%=r;
    cout<<q[K+nr]<<endl;
  }
  return 0;  
}