#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,M,n;
  cin>>N>>M>>n;
  vector<int> A(N);
  A[0]=n/2;
  int k=0;
  for(int i=n/2;i%2==0;i/=2)
    k++;
  for(int i=1;i<N;i++){
    cin>>A[i];
    A[i]/=2;
    int l=0;
    for(int j=A[i];j%2==0;j/=2){
      l++;
    }
    if(k!=l){
      cout<<0<<endl;
      return 0;
    }
  }
  k=A[0];
  for(int i:A){
    k=k/__gcd(k,i)*(i);
    if(k>M){
      cout<<0<<endl;
      return 0;
    }
  }
  cout<<(M+k)/k/2<<endl;
}