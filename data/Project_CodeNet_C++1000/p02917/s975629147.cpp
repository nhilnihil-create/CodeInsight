#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  int N;
  cin>>N;
  vector<int> B(N-1);
  rep(i,N-1) cin>>B[i];
  vector<int> A(N);
  A[0]=B[0];
  for(int i=1;i<N-1;i++){
    A[i]=min(B[i-1],B[i]);
  }
  A[N-1]=B[N-2];
  int sum=0;
  for(int i=0;i<N;i++) sum+=A[i];
  cout<<sum<<endl;
}