#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,m; cin>>n>>m;
  vector<int> a(n);
  for(int i=0; i<n; ++i) cin>>a[i];
  long double sum=0,res=0;
  for(int i=0; i<n; ++i) sum+=a[i];
  sum/=4*m;
  for(int i=0; i<n; ++i) if(a[i]>=sum) ++res;
  if(res>=m) cout<<"Yes"; else cout<<"No";
  return 0;
}
