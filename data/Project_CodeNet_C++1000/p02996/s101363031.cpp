#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int,int>> a(n);
  for(int i=0;i<n;i++) cin >> a.at(i).second >> a.at(i).first;
  
  sort(a.begin(),a.end());
  
  int time=0;
  string s="Yes";
  
  for(int i=0;i<n;i++){
    time+=a.at(i).second;
    if(a.at(i).first<time){
      s="No";
      i=n;
    }
  }
  cout << s << endl;
}