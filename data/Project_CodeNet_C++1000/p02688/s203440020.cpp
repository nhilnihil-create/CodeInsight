#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,k;cin>>n>>k;
  int c,d,i,j,cnt=0;
  vector<int> a(n,0);
  for(i=0; i<n; ++i){
    cin>>d;
    for(j=0; j<d; ++j){ cin>>c;a[c-1]++;}
  }
  for(i=0; i<n; ++i)
    if(a[i]==0) ++cnt;
  cout<<cnt<<endl;
  return 0;
}
      
