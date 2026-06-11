#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int N,K;
  cin>>N>>K;
  vector<int>P(N),C(N);
  for(int i=0;i<N;i++){cin>>P[i];P[i]--;}
  for(int i=0;i<N;i++){cin>>C[i];}
  int64_t ans=-INF;
  for(int i=0;i<N;i++){
    int x=i;
    vector<int>s;
    int64_t tot=0;
    while(true){
      x=P[x];
      s.push_back(C[x]);
      tot+=C[x];
      if(x==i){break;}
    }
    int l=s.size();
    int64_t t=0;
    for(int j=0;j<l;j++){
      t+=s[j];
      int64_t now=t;
      if(j+1>K){break;}
      if(tot>0){
        int r=(K-(j+1))/l;
        now+=tot*r;
      }
      chmax(ans,now);
    }
  }
  cout<<ans<<endl;
  return 0;  
}