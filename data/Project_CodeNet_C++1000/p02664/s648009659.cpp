#include<bits/stdc++.h>
using namespace std;
int main(){
  string s; cin >> s;
  for(int i = 0; i < s.size(); i++){
    if(s.at(i) == '?'){
      s.at(i) = 'D';
    }
  }
  cout << s << endl;
}
        
  