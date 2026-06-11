#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int>ten(n);
  double su=0;
  for(int i=0;i<n;i++){
    cin >> ten.at(i);
    su+=ten.at(i);
  }
  sort(ten.begin(),ten.end(),greater());
  bool ans=true;
  for(int i=0;i<m;i++){
    if(ten.at(i)<su/4/m)
      ans=false;
  }
  cout << (ans?"Yes":"No") << endl;
  return 0;
}