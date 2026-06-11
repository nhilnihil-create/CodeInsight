#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  string s; cin >> s;

  rep(i,s.size()){
    if(s[i]+n>'Z'){
      s[i] -= 65;
      s[i] += n;
      s[i] %= 26;
      s[i] += 65;
    }
    else{
      s[i]+=n;
    }
  }

  cout << s << endl;
  
  return 0;
}
