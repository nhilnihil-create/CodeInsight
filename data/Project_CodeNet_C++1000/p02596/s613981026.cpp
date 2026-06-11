#include<iostream>
using namespace std;
using ll = long long;

int main() {
  ll K,a,i;
  cin>>K;
  a=7%K;
  for(i=1;i<=K && a>0;i++) {
    a=(a*10+7)%K;
  }
  cout<<(a==0 ? i : -1)<<endl;
  return 0;
}
