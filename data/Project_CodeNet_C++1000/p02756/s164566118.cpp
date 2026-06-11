#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

/*int main(){
  string s;
  cin >> s;
  deque<char> d;
  d.push_back('S');
  int q;
  cin >> q;
  bool flag = true;
  rep(i,q){
    int ti;
    cin >> ti;
    cout << "ti " << ti << endl;
    if (ti == 1){
      flag = flag? false : true;
    }
    else {
      int fi;
      char ci;
      cin >> fi >> ci;
      cout << "fi " << fi << endl;
      cout << "ci " << ci << endl;
      cout << "flag " << flag << endl;
      if (flag){
        if (fi == 1) d.push_front(ci);
        else d.push_back(ci);
      }
      else {
        if (fi == 1 ) d.push_back(ci);
        else d.push_front(ci);

      }
    }
    for(auto c : d) cout << c;
    cout << endl;
    cout << endl;
  }
  while (!d.empty()){
    if (flag){
      char c = d.front();
      if (c == 'S'){
        cout << s;
        d.pop_front();
        continue;
      }
      cout << c;
      d.pop_front();
    }
    else {
      reverse(s.begin(), s.end());
      char c = d.back();
      if (c == 'S'){
        cout << s;
        d.pop_back();
        continue;
      }
      cout << c;
      d.pop_back();
    }
  }
  cout << endl;
  return 0;
}*/

int main(){
  string s;
  cin >> s;
  int q;
  cin >> q;
  string t;
  rep(i,q){
    int ti;
    cin >> ti;
    if (ti == 1){
      swap(s, t);
    }
    else {
      int fi;
      char ci;
      cin >> fi >> ci;
      if (fi == 1) t += ci;
      else s += ci;
    }
  }
  reverse(t.begin(), t.end());
  t += s;
  cout << t << endl;
  return 0;
}
