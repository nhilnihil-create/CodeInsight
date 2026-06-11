#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}


int main() {
  int N,M,X;
  cin>>N>>M>>X;
  int C[100];
  int A[100][100];
  for(int i=0;i<N;i++){
      cin>>C[i];
      for(int j=0;j<M;j++){
         cin>>A[i][j];
      }
  }
  int ans=10000000;
  for(int s=0;s<(1<<N);s++){
      int p=0;
      vector<int>table(M);
      for(int i=0;i<N;i++){
          if((s>>i)&1){
             for(int j=0;j<M;j++){
                 table[j]+=A[i][j];
             }
             p+=C[i];}
      }
      bool ok=true;
      for(int j=0;j<M;j++){
          if(table[j]<X){ok=false;}
          //cout<<table[j];
      }//cout<<endl;
      if(ok){ans=min(ans,p);}
  }
  if(ans==10000000){cout<<-1<<endl;}
  else{cout<<ans<<endl;}
  return 0;
}