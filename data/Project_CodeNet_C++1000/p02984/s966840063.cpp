#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<long long>a(n+1);
  vector<long long>b(n+1);
  long long s=0;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    s+=a[i];
  }
  for(int i=2;i<=n-1;i+=2) s-=2*a[i];
  b[1]=s;
  for(int i=2;i<=n;i++){
    b[i]=2*a[i-1]-b[i-1];
  }
  for(int i=1;i<=n;i++) cout<<b[i]<<" ";
}
