#include <bits/stdc++.h>
using namespace std;
int main(){
  map<char,int>	data;
  for(int i=0;i<4;i++){
    char c;	cin >> c;
    data[c]++;
  }
  
  if(data.size()==2){
    bool	ok=true;
    for (auto p : data) {
      auto v = p.second;
      if(v!=2)	ok=false;
    }
    if(ok)	cout << "Yes";
    else	cout << "No";
  }
  else cout << "No";
}