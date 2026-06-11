#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N,ans=0;
  cin>>N;
  vector<int> a(N+1);
  for (int i=1;i<=N;i++) {
    cin>>a[i];
    if (i%2==1 && a[i]%2==1) ans++;
  }
  cout<<ans<<endl;
  return 0;
}
