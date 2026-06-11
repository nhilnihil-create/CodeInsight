#include<bits/stdc++.h>
using namespace std;
int main(void){
  int i,n;cin>>n;
  vector<int> a(n),b(n);
  for(i=0; i<n; ++i) cin>>a[i]>>b[i];
  sort(a.begin(),a.end()), sort(b.begin(),b.end());
  int cnt=0;
  if(n%2==1) cnt=b[(n+1)/2-1]-a[(n+1)/2-1]+1;
  else cnt=(b[n/2-1]+b[n/2])-(a[n/2-1]+a[n/2])+1;
  cout << cnt << endl;
  return 0;
}
