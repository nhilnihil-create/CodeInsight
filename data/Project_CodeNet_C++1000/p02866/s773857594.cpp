#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,d;
  cin>>N>>d;
  if(d!=0){
    puts("0");
    return 0;
  }
  vector<int> A(N,0);
  A[0]=1;
  for(int i=0;i<N-1;i++){
    int D;
    cin>>D;
    if(D>=N){
      puts("0");
      return 0;
    }
    A[D]++;
  }
  if(A[0]!=1){
    puts("0");
    return 0;
  }
  int ans=1;
  bool b=true;
  for(int i=1;i<N;i++){
    if(!b && A[i]!=0){
      puts("0");
      return 0;
    }
    for(int j=0;j<A[i];j++)
      ans=ans*A[i-1]%998244353;
    b=A[i];
  }
  cout<<ans<<endl;
}