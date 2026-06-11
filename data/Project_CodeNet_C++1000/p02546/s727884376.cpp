#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  string S; cin >> S;
  string ans = S;
  if(S.size() == 1){
    if(S[0] == 's'){
      ans += "es";
    } else { 
      ans += "s";
    }
  } else {
    if(S[S.size()-1] == 's'){
      ans += "es";
    } else {
      ans += "s";
    }
  }
  cout << ans << endl;
}
