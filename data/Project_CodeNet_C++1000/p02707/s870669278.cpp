#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  vector<int> a(n-1),b(n,0);
  for(int i=0; i<n-1; ++i){ cin>>a[i]; ++b[a[i]-1];}
  for(int i=0; i<n; ++i) cout<<b[i]<<endl;
  return 0;
}
