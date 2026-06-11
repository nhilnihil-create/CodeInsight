#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  string s;cin >> s;
  if(s[s.length()-1] == 's')cout << s + "es" << endl;
  else cout << s + "s" << endl;
  return 0;
}