#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int fr = -1;
  vector<int> r;
  vector<char> c(n);
  for(int i=0;i<n;i++){
    cin >> c[i];
    if(fr<0)fr=i;
    if(c[i]=='R'){
      r.push_back(i);
    }
  }
  int rn = r.size();

  if(fr+1>rn){
    cout << rn << endl;
    return 0;
  }

  r.pop_back();
  // for(int i=0;i<r.size()+1;i++){
  //   cout << r[i];
  // }
  // cout <<  endl;

  int cnt=0;
  for(int i=0;i<n;i++){
    if(i>=r[r.size()]){
      break;
    }
    if(c[i]!='R'){
      cnt++;
      r.pop_back();
    }
  }
  

  cout << cnt << endl;
  return 0;
}
