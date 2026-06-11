#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;
int main(){
  string s;
  int q;
  cin >> s >> q;
  string s1 = "",s2 = "";
  bool rev = true;

  rep(i,q){
    int t; cin >> t;
    if(t==1){
      rev = !rev;
    }else if(t==2){
      int f;
      char c;
      cin >> f >> c;
      if(f==1){
        if(rev) s1.push_back(c);
        else s2.push_back(c);
      }else if(f==2){
        if(rev) s2.push_back(c);
        else s1.push_back(c);
      }
    }
  }

  if(rev){
    reverse(all(s1));
    cout << s1 + s + s2 << endl;
  }else{
    reverse(all(s));
    reverse(all(s2));
    cout << s2 + s + s1 << endl;
  }

}
