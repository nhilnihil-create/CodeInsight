#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m; cin >> n >> m;
  vector<bool> v(n,true);
  vector<int> b(n);
  int a = 0,w = 0;
  int c; string s;
  for(int i=0;i<m;i++){
      cin >> c >> s;
      if(v[c-1]){
          if(s == "AC"){
              v[c-1] = false;
              a++;
              w += b[c-1];
          }else{
              b[c-1]++;
          }
      }
  }
  cout << a << " " << w << endl;
}