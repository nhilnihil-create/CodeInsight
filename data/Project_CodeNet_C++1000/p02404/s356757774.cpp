#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
  vector<pair<int,int> > v;
  int a, b;
  while(cin >> a >> b && (a || b)){
    v.push_back(make_pair(a, b));
  }
  for(int i=0;i<(int)v.size();i++){
    for(int j=0;j<v[i].first;j++){
      for(int k=0;k<v[i].second;k++){
        if(j==0 || k==0 || j==v[i].first-1 || k==v[i].second-1){
          cout << "#";
        }else{
          cout << ".";
        }
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}