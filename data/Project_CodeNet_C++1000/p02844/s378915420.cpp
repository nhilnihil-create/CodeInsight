#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int main(){
  int n;
  string s;
  cin>>n>>s;
  ll count = 0;
  rep(i,10) rep(j,10) rep(k,10){
    string pin = to_string(i) + to_string(j) + to_string(k);
    int p1 = 0;
    int p2 = 0;;
    bool ok1 = false;
    rep(l,n){
      if (pin[0]==s[l]){
        p1 = l;
        ok1 = true;
        break;
      }
    }
    bool ok2 = false;
    for (int l=p1+1; l<n; l++){
      if (pin[1]==s[l]){
        p2 = l;
        ok2 = true;
        break;
      }
    }
    bool ok3 = false;
    for (int l=p2+1; l<n; l++){
      if (pin[2]==s[l]){
        ok3 = true;
        break;
      }
    }
    if (ok1==true && ok2 ==true && ok3 ==true) count++;
  }
  cout << count << endl;
}