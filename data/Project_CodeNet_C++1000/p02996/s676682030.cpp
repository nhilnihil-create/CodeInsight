#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int,int>>a(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i).second >> a.at(i).first;
  sort(a.begin(),a.end());
  int s=0;
  bool ans=true;
  for(int i=0;i<n;i++){
    s+=a.at(i).second;
    if(s>a.at(i).first)
      ans=false;
  }
  cout << (ans?"Yes":"No") << endl;
  return 0;
}