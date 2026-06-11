#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b,c,d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  for(int i = a;i < d;i++){
    if(s[i] == '#' && s[i+1] == '#'){
      cout << "No" << endl;
      return 0;
    }
  }
  if(c < d){
    cout << "Yes" << endl;
    return 0;
  }
  else{
    for(int i = b-2;i <= d-2;i++){
      if(s[i] == '.' && (s[i+1] == '.' && s[i+2] == '.')){
        cout << "Yes" << endl;
        return 0;
      }
    }
    cout << "No" << endl;
  }
}
