#include<iostream>
using namespace std;
using ll = long long;

int main() {
  ll N,i,j,ans = 0;
  cin>>N;
  for (i=1;i<=N;i++) {
    j=N/i;
    ans += j*(j+1)/2*i;
  }
  cout<<ans<<endl;
  return 0;
}
