#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  a--; b--; c--; d--;
  
  string s;
  cin >> s;
  
  if (c < d){
    int ok = 1;
    for (int i = a; i < c; i++){
      if (s[i] == '#' && s[i + 1] == '#')
        ok = 0;
    }
    for (int i = b; i < d; i++){
      if (s[i] == '#' && s[i + 1] == '#')
        ok = 0;
    }
    if (ok)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  else {
    int ok = 1;
    for (int i = a; i < c; i++){
      if (s[i] == '#' && s[i + 1] == '#')
        ok = 0;
    }
    for (int i = b; i < d; i++){
      if (s[i] == '#' && s[i + 1] == '#')
        ok = 0;
    }
    if (ok){
      ok = 0;
      for (int i = b - 1; i < d; i++){
        if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.')
          ok = 1;
      }
      if(ok)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
    else 
      cout << "No" << endl;
  }

  return 0;
}
