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
  string front = "", end = "";
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
        if(cnt%2 == 0) front = t+front;
        else end += t;
      }
      else{
        if(cnt%2 == 0) end += t;
        else front = t + front;
      }
    }
  }
  if(cnt%2 == 0) cout << front + s + end << endl;
  else{
    reverse(s.begin(),s.end());
    reverse(end.begin(),end.end());
    reverse(front.begin(),front.end());
    cout << end + s + front << endl;
  }
}
