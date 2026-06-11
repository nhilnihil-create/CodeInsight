#include <iostream>
#define ll long long
using namespace std;

int main() {
  ll n, a, b, c, d;
  string m;
  cin >> n >> a >> b >> c >> d;
  cin >> m;
  a--;
  b--;
  c--;
  d--;
  for (int i = a; i < c; i++){
    if (m[i] == '#' && m[i+1] == '#'){
      cout << "No" << endl;
      return 0;
    }
  }

  for (int i = b; i < d; i++){
    if (m[i] == '#' && m[i+1] == '#'){
      cout << "No" << endl;
      return 0;
    }
  }

  if ( d < c){
    for (int i = b; i <= d; i++){
      if (m[i] == '.' && m[i-1] == '.' && m[i+1] == '.'){
        cout << "Yes" << endl;
        return 0;
      }
    }
    cout << "No" << endl;
  }
  else 
    cout << "Yes" << endl;

  return 0;
}