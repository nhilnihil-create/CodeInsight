#include<bits/stdc++.h>
using namespace std;
int main(void){
  int a,n; cin>>n;
  vector<int> b(n,0);
  for(int i=0; i<n-1; ++i){ cin>>a; ++b[a-1];}
  for(int i=0; i<n; ++i) cout<<b[i]<<endl;
  return 0;
}
