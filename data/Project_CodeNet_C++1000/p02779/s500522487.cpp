#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,a;
  cin >> n;
  set<int> s;
  bool t=true;
  for(int64_t i=0;i<n;i++){
    cin >> a;
    s.insert(a);
  }
  if(s.size()==n)cout << "YES" << endl;
  else cout << "NO" << endl;
}
