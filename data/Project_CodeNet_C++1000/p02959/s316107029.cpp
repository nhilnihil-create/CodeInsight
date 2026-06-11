#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
int mod = 1000000007;
long long dp[100005];

int main() {
  int n;
  cin >> n;
  
  int a[n+1],b[n];
  for(int i = 0;i< n+1;i++){
    cin >> a[i];
  }
  for(int i = 0;i< n;i++){
    cin >> b[i];
  }
  long long c = 0;
  for(int i = 0;i< n;i++){
    if(b[i] <= a[i]){
      c += b[i];
    }else if(b[i] <= a[i] + a[i+1]){
      c+= b[i];
      a[i+1] -= (b[i] -a[i]);
    }else if(b[i] >a[i] + a[i+1]){
      c += (a[i]+a[i+1]);
      a[i+1] = 0;
    }
  }
  
  cout << c;
  
}
