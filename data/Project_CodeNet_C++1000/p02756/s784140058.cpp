#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  string s;
  cin >> s;
  int rev = 0;
  int q;
  cin >> q;
  while (q--){
    int t;
    cin >> t;
    if (t == 1){
      rev = (rev + 1) % 2;
      continue ;
    }
    int f;
    cin >> f;
    char c;
    cin >> c;
    if (f == 1 && rev) s += c;
    else if (f == 2 && !rev) s += c;
    else s = c + s;
  }
  if (rev) reverse(s.begin(), s.end());
  cout << s << endl;
}