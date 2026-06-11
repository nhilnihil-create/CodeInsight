#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n,k;
  cin >> n >> k;
  if(n>=k)cout << min(n%k,k-n%k);
  else cout << min(k-n,n);
  return 0;
}