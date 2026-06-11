#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  string S,T; cin >> S >> T;

  string ans = "";
  for(int i = 0; i < N; i++){
    ans += S[i];
    ans += T[i];
  }
  cout << ans << endl;
}
