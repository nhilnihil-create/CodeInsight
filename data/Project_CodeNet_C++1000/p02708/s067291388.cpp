#include <bits/stdc++.h>
using namespace std;

long long sum(long l,long r){
  return (l+r)*(r-l+1)/2;
}

int main(){
  int n,k;
  cin >> n >> k;
  long long ans=0;
  for(int i = k;i <= n+1; i++){
    long long small = sum(0,i-1);
    long long large = sum(n-i+1,n);
    //cout << small <<" " <<  large << endl;
    ans += large - small + 1;
  }
  cout << ans % 1000000007 << endl;
}