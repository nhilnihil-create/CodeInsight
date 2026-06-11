#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  vector<pair<int,string>> input(m);
  for(int i=0;i<m;i++){
    int p;
    string res;
    cin >> p >> res;
    --p;
    input.at(i) = make_pair(p,res);
  }
  
  vector<int> wa(n,0);
  vector<bool> ac(n,false);
  
  for(int i=0;i<m;i++){
    int p = input.at(i).first;
    string res = input.at(i).second;
    if(!ac.at(p) && res == "WA"){
      wa.at(p)++;
    }else if(res == "AC"){
      ac.at(p) = true;
    }
  }
  
  int acnum=0;
  int wanum=0;
  for(int i=0;i<n;i++){
    if(ac.at(i)){
      acnum++;
      wanum += wa.at(i);
    }
  }
  
  cout << acnum << " " << wanum << endl;
  
  return(0);
}