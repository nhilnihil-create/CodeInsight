#include<bits/stdc++.h>
using namespace std;
int main(void){
  int h,n; cin>>h>>n;
  int sum=0,l;
  for(int i=0; i<n; ++i){ cin>>l; sum+=l;}
  if(h>sum) cout<<"No"; else cout<<"Yes";
  return 0;
}
