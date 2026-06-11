#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll N,i,ans;
  ll A[222222];
  cin >> N;
  for(i=0;i<=N-1;i++)
    cin >> A[i];
  sort(A,A+N,greater<int>());
  ans = A[0];
  for(i=0;i<=N-3;i++)
    ans += A[i/2+1];
  cout << ans << endl;
}