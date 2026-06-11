#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  string s;
  cin >> s;
  s += '.';
  s += '.';
  if(c < d) {
    for(int i = a - 1; i < d - 1; i++){
      if(s[i] == s[i + 1] && s[i] == s[i + 2] && s[i] == '#'){
        cout << "No\n";
        return 0;
      }
    }
    cout << "Yes\n";
  }else{
    for(int i = a - 1; i < c - 1; i++){
      if(s[i] == s[i + 1] && s[i] == s[i + 2] && s[i] == '#'){
        cout << "No\n";
        return 0;
      }
    }
    bool ok = false;
    for(int i = b - 2; i < d - 1; i++){
      if(s[i] == s[i + 1] && s[i] == s[i + 2] && s[i] == '.'){
        ok = true;
      }
    }
    if(ok){
      cout << "Yes\n";
    }else{
      cout << "No\n";
    }
  }
  
  return 0;
}