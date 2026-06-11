#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;	cin >> n >> m;
  vector<int>	s(m);
  vector<char>	c(m);
  for(int i=0;i<m;i++){
    cin >> s.at(i) >> c.at(i);
    s.at(i)--;
  }
  
  for(int i=0;i<1000;i++){
    bool ok=true;
    string num=to_string(i);
    if(num.size()!=n){
      ok=false;
    }else{
      for(int x=0;x<m;x++){
        if(s.at(x)<n){
          if(num.at(s.at(x))!=c.at(x)){
            ok=false;
          }
        }
      }
    }
    if(ok){
      cout << num;
      return 0;
    }
  }
  cout << -1;
}