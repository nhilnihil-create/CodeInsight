#include<bits/stdc++.h>
using namespace std;

int64_t fib(int n){
  int64_t a=0,b=1;
  for(int i=0;i<n;i++){
    a=(a+b)%1000000007;
    b=(a-b+1000000007)%1000000007;
  }
  return a;
}

int main(){
  int64_t n,m,ans=1;
  cin >> n >> m;
  vector<int>br(m);
  for(int i=0;i<m;i++)
    cin >> br.at(i);
  int x=0;
  for(int i=0;i<m;i++){
    ans=(ans*fib(br.at(i)-x))%1000000007;
    x=br.at(i)+1;
  }
  ans=(ans*fib(n-x+1))%1000000007;
  cout << ans << endl;
  return 0;
}
      