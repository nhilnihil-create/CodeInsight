#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef vector<int> VI;
typedef vector<ll> VLL;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  string s;
  cin >> s;
  
  sort(s.begin(), s.end());

  if(s[0] == s[1] && s[1] != s[2] && s[2] == s[3]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}