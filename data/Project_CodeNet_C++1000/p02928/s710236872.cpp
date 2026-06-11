#include <bits/stdc++.h>
using namespace std;

int main(){
  long long K,n;
  cin >> n >> K;
  int A[n];
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  long long srn=0,drn=0,ans=0;
  for(int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
      if(A[i]>A[j]) srn++;
    }
  }
  for(int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if(A[i]>A[j]) drn++;
    }
  }
  long long comb=(K*(K-1)/2)%1000000007; 
  ans=(srn*K%1000000007+(drn*comb)%1000000007)%1000000007;
  cout<<ans<<endl;
  return 0;
}