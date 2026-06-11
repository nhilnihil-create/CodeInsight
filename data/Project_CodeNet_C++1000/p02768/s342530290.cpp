#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000000007;
int p(int A,int B){
  if(A==0)
    return 1;
  if(A%2==0){
    int j=p(A/2,B);
    return j*j%N;
  }
  return B*p(A-1,B)%N;
}
signed main(){
  int n,a,b;
  cin>>n>>a>>b;
  int a1=1,a2=1,b1=1,b2=1;
  for(int i=n-a+1;i<=n;i++)
    a1=a1*i%N;
  for(int i=1;i<=a;i++)
    a2=a2*i%N;
  for(int i=n-b+1;i<=n;i++)
    b1=b1*i%N;
  for(int i=1;i<=b;i++)
    b2=b2*i%N;
  cout<<(p(n,2)-(a1*p(N-2,a2)%N+b1*p(N-2,b2)%N+1)+N*3)%N<<endl;
}