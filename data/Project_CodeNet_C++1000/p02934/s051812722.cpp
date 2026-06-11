#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(int)n; i++)
int main(){
  cout<<fixed<<setprecision(10);
  int N;cin>>N;
  vector<double> A(N);
  double by = 1;
  rep(i,N){
    cin>>A[i];
    by *= A[i];
  }
  double sum = 0;
  rep(i,N){
    sum += by/A[i];
  }
  cout<<by/sum<<endl;
}