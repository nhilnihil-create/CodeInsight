#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main(){
 string s;
      int c = 0;
  cin >> s;
  string t = s;
  int a = s.size();
  rep(i,a){
    t[s.size() - i-1] = s[i];
  }
  int counts =0;
  rep(i,a){
   if(s[i] == t[i]) counts++;    
  }
  if(counts != a) cout << "No" << endl;
  else{
    int b = (a-1)/2;

    rep(i,b){
    if(s[i] == t[i+b+1] && s[i+b+1] == t[i]) c++;
    }
  if(c == b) cout << "Yes" << endl;
  else cout << "No" << endl;
  }
}