#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll N,i;
  ll A[222222],B[222222];
  cin >> N;
  for(i=0;i<=N-1;i++)
    cin >> A[i] >> B[i];
  sort(A,A+N);
  sort(B,B+N);
  ll min,max,ans;
  if(N%2==0){
    min = (A[N/2] + A[N/2-1]);
    max = (B[N/2] + B[N/2-1]);
    ans = max - min + 1;
  }
  else{
    min = A[(N-1)/2];
    max = B[(N-1)/2];
    ans = max - min + 1;
  }
  cout << ans << endl;
}

