#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t N; cin>>N;
  vector<int64_t> A(N),B(N);
  rep(i,N) cin>>A[i]>>B[i];
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  if(N%2==1){
    cout<<B[(N+1)/2-1]-A[(N+1)/2-1]+1;
  }
  else{
    cout<<(B[N/2-1]+B[N/2])-(A[N/2-1]+A[N/2])+1;
  } 
}