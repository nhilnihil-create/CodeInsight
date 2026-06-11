#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;
//const ll MOD=998244353;

int main(){
  int N; cin>>N;
  ll A[N],B[N]; rep(i,N) cin>>A[i]>>B[i];
  sort(A,A+N);
  sort(B,B+N);
  if(N%2){
    cout<<B[N/2]-A[N/2]+1<<endl;
  }else{
    cout<<(B[N/2-1]+B[N/2])-(A[N/2-1]+A[N/2])+1<<endl;
  }
  return 0;
}