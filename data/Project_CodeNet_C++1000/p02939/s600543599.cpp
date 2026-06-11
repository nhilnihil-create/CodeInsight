#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  

int main(){
  string s; cin >> s;
  string bef = "", now="";

  ll cnt=0;
  for(int i=0; i<s.size(); i++){
    now += s[i];
    if(bef==now) continue;
    bef=now;   now="";  cnt += 1;
  }
  cout << cnt << endl;
}
