#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  long long H,N,X,SUM=0;
  cin>>H>>N;
  rep(i,N){cin>>X;SUM+=X;}
  if(H>SUM){cout<<"No"<<endl;}else{cout<<"Yes"<<endl;}
}
