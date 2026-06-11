#include <iostream>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[n+1];
  for (int i=1;i<=n;i++){
    cin>>a[i];
    a[i+1]=0;
  }
  int ans=0;
  for (int i=1;i<=n;i+=2){
    if (a[i]%2==1) ans++;
  }
  cout<<ans<<endl;
  return 0;
}