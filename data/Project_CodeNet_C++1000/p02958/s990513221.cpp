#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>g){
  int n=0;
  for(int i=0;i<g.size();i++){
    if(n>g.at(i))
      return false;
    n=g.at(i);
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  vector<int>kaz(n);
  for(int i=0;i<n;i++)
    cin >> kaz.at(i);
  bool ok=check(kaz);
  if(!ok){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i!=j){
        swap(kaz.at(i),kaz.at(j));
        ok=check(kaz);
        swap(kaz.at(i),kaz.at(j));
        if(ok)
          break;
      }
    }
    if(ok)
      break;
  }
  }
  cout << (ok?"YES":"NO") << endl;
  return 0;
}