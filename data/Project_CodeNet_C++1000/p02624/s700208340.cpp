#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n;
  cin >> n;
  long a = 2;
  long hyo[n+1];
  rep(i,n+1){
    hyo[i] = 1;
  }
  while(a<=n){
    long ai = a;
    long i = 1;
    while(ai*i<=n){
      hyo[ai*i] += 1;
      i++;
    }
    a++;
  }
  long ans = 0;
  for(int i=1;i<n+1;i++){
    ans += i*hyo[i];
  }
  cout << ans << endl;
  return 0;
}