#include<bits/stdc++.h>
using namespace std;
main(){
  vector<int> v;
  for(int i=0; i<3; i++){int a; cin>>a; v.push_back(a);}
  sort(v.begin(), v.end());
  for(int i=0; i<2; i++) cout<<v[i]<<" ";
  cout<<v[2]<<"\n";
}
