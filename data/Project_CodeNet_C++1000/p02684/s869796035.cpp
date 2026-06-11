#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int64_t N,K;
  cin>>N>>K;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
    A[i]--;
  }
  vector<int>id(N,-1);
  vector<int>past;
  int now=0;
  while(id[now]==-1){
    if(past.size()==K){cout<<now+1<<endl;return 0;}
    id[now]=past.size();
    past.push_back(now);
    
    now=A[now];
  }
  int roop=past.size()-id[now];
  int x=(K-id[now])%roop;
  cout<<past[id[now]+x]+1<<endl;
  return 0;  
}