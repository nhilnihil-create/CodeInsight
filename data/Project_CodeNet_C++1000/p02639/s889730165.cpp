#include<iostream>
using namespace std;

int main() {
  int i,a,ans;
  for (i=1;i<=5;i++) {
    cin>>a;
    if (a==0) ans=i;
  }
  cout<<ans<<endl;
  return 0;
}
