#include<bits/stdc++.h>
using namespace std;
main(){
  vector<int>v(5); for(int i=0; i<5; i++) cin>>v[i];
  if((v[0]>=v[2]+v[4])&&(v[1]>=v[3]+v[4])&&(v[2]-v[4]>=0)&&(v[3]-v[4]>=0))cout<<"Yes";
  else cout<<"No";
  cout<<"\n";
}
