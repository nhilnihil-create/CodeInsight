#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    int l;
    cin>>l;
    a[i]=l+1;
  }
  long long m=1000000007;
  int b[n];
  for(int i=0;i<n+1;i++)b[i]=0;
  long long dp[100010];
    dp[0]=1;
  b[0]=3;
  for(int i=1;i<n+1;i++){
    dp[i]=(dp[i-1]*b[a[i-1]-1])%m;
    b[a[i-1]]++;
    b[a[i-1]-1]--;
  }
  cout<<dp[n]<<endl;
}
