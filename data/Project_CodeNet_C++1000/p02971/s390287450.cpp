#include <bits/stdc++.h>
using namespace std;
int main(void){
  int a;
  int cnt = 0;
  cin >> a;
  vector<int> ans(a);
  vector<int> v(2);
  cin >> v[0] >> v[1];
  ans[0] = v[0];
  ans[1] = v[1];
  if(v[0] == v[1]){
      v[0] = 0;
      cnt++;
  }
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  for(int i=0;i<a-2;i++){
      int d;
      cin >> d;
      ans[i+2] = d;
     if(d>v[0]){
         cnt = 0;
         v[1] = v[0];
         v[0] = d;
     }else if(d>v[1]){
         v[1] = d;
     }else if(d == v[0])cnt++;
  }
  for(int i=0;i<a;i++){
      if(cnt > 0) cout << v[0] << endl;
      else{
          if(ans[i] == v[0])cout << v[1] << endl;
          else cout << v[0] << endl;
      }
  }
}
