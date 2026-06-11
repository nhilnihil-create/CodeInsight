#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  if(a==b&&b==c){
    cout << "No" << endl;
    return 0;
  }
  if(a==b||b==c||c==a){
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}
