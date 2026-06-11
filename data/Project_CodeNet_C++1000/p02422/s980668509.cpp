#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  string str; cin >> str;
  int n; cin >> n;
  for(int i=0; i<n; i++){
    string op; cin >> op;
    int a, b;
    cin >> a >> b;

    if(op == "print")
      cout << str.substr(a, b-a+1) << endl;

    else if (op == "replace"){
      string p; cin >> p;
      str = str.substr(0, a) + p + str.substr(b+1);
      //cout << str << endl;

    }else if(op == "reverse"){
      string p = str.substr(a, b-a+1);
      reverse(p.begin(), p.end());
      str = str.substr(0, a) + p + str.substr(b+1);
      //cout << str <<endl;
    }

  }

  return 0;
}