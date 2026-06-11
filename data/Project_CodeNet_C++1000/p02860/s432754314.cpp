#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  string s; cin >> s;
  if(n % 2 == 1){
    cout << "No";
    return 0;
  }
  for(int i = 0; i < n/2; i++){
   // cout << s.at(i) << "  " << s.at(i+n/2) << endl;
    if(s.at(i) != s.at(i + n/2)){
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}