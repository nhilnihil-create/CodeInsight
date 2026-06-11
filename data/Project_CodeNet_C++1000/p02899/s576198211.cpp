#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int,int>>ka(n,pair<int,int>(0,0));
  for(int i=0;i<n;i++){
    cin >> ka.at(i).first;
    ka.at(i).second=i+1;
  }
  sort(ka.begin(),ka.end());
  for(int i=0;i<n;i++){
    cout << ka.at(i).second;
    if(i<n-1)
      cout << " ";
  }
  cout << endl;
  return 0;
}