#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  string s;
  int q;
  cin >> s >> q;
  int cnt = 0;
  rep(i,q){
    int a;
    cin >> a;
    if(a == 1) cnt ++;
    else{
      int f;
      cin >> f;
      string t;
      cin >> t;
      if(f == 1){
        if(cnt%2 == 0) s = t + s;
        else s += t;
      }
      else{
        if(cnt%2 == 0) s += t;
        else s = t + s;
      }
    }
  }
  if(cnt%2 == 0) cout << s << endl;
  else{
    reverse(s.begin(),s.end());
    cout << s << endl;
  }
}
