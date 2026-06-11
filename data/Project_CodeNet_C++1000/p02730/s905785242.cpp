#include <iostream>
#include <string>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;
 
int main(){
  string s;
  cin >> s;
  rep(i,(s.size()+1)/4){
    if(s[i]!=s[(s.size()-1)/2-1-i]){
      cout << "No" << endl;
      return 0;
    }
  }
  rep(i,(s.size()+1)/4){
    if(s[i+(s.size()+3)/2-1]!=s[s.size()-i-1]){
      cout << "No" << endl;
      return 0;
    }
  }
  rep(i,s.size()/2){
    if(s[i]!=s[s.size()-i-1]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}