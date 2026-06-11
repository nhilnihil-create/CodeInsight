#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n;
  cin >> n;
  long ans = 0, nn = n;
  for(long i=2;i<=sqrt(nn);i++){
    if(n%i!=0) continue;
    long tmp = 0;
    while(n%i==0){
      tmp++;
      n /= i;
    }
    long num = 1;
    while(1){
      if((num*(num+1))/2 <= tmp) num++;
      else break;
    }
    ans += num-1;
  }
  if(n!=1)ans++;
  cout << ans << endl;
  return 0;
}