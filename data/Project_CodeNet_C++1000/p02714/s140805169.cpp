#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  string S; cin >> S;

  map<char,ll> m;
  for(auto c: S){
    m[c]++;
  }

  ll ans = m['R'] * m['G'] * m['B'];

  for(int j = 1; j < N-1; j++){
    for(int p = 1; (j-p>=0) && (j+p<N); p++){
      if(S[j] != S[j-p] && S[j] != S[j+p] && S[j-p] != S[j+p]){
        ans--;
      }
    }
  }
  cout << ans << endl;
}

