#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)


int main() {
  int N;
  cin>>N;
  vector<int>P(N);
  vector<int>Q(N);
  rep(i,N){
      cin>>P[i];
  }
  rep(i,N){
      cin>>Q[i];
  }
  vector<int>R(N);
  rep(i,N){
      R[i]=i+1;
  }
  int c=0;
  int d=0;
  int cnt=1;
  while(next_permutation(R.begin(),R.end())){
      bool a=true;
      bool b=true;
      rep(i,N){
          if(R[i]==P[i]){
          }
          else{
              a=false;
          }
          if(R[i]!=Q[i]){
              b=false;
          }
      }
      if(a==true){
          c=cnt;
      }
      if(b==true){
          d=cnt;
      }
    cnt++;
  }
  cout<<abs(c-d)<<endl;
}
