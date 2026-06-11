#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;
  string r="";
  for(int i = s.size()-1;i>=0;i--) r+=s[i];

  int hug = 0;
  rep(i,s.size()){
    if(s[i]!=r[i]) hug++;
  }

  hug /= 2;
  cout << hug << endl;
  return 0;
}
