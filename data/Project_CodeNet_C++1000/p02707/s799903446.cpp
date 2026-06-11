#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;cin>>n;vector<int>v(n-1);
  vector<int>vv(n+1,0);
  for(int i=0;i<n-1;i++){
    cin>>v.at(i);
    vv.at(v.at(i)-1)++;
  }
  for(int j=0;j<n;j++)cout<<vv.at(j)<<endl;
}
