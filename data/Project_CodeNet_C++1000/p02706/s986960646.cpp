#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  vector<int>v(m);int a=0;
  for(int i=0;i<m;i++){
    cin>>v.at(i);a+=v.at(i);
  }
  cout<<max(n-a,-1)<<endl;
}
