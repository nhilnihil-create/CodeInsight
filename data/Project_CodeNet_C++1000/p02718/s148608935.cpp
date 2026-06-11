#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;cin>>n>>m;
  vector<int>v(n);int o=0;
  for(int i=0;i<n;i++){
    cin>>v.at(i);o+=v.at(i);
  }
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  int a=4*m;
  o=(o+a-1)/a;
  for(int i=0;i<m;i++){
    if(v.at(i)<o){
      cout<<"No"<<endl;
      exit (0);
    }
  }cout<<"Yes"<<endl;
}
