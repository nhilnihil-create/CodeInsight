#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  string S,T;
  cin >> S;
  cin >> T;
  int ans = 0;
  for(int i = 0; i < S.size(); i++){
    if(S[i] != T[i]) ans++;
  }
  cout << ans << endl;
}
