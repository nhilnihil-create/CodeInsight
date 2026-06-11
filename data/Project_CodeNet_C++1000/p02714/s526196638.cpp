#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
  FAST
  int N; 
  cin >> N;
  string S; 
  cin >> S;
  map<char,int> toIdx = {
    {'R', 0},
    {'G', 1},
    {'B', 2},
  };
  vector<ll> cnt(3);
  for(int i=0;i<N;i++) cnt[toIdx[S[i]]]++;
 
  ll ans = 1;
  for(int i=0;i<3;i++) ans *= cnt[i];
  for(int j=0;j<N;j++)
   for(int i=0;i<j;i++){
    int k = j + j - i;
    if (k < N) {
      if (S[i] == S[j]) continue;
      if (S[i] == S[k]) continue;
      if (S[k] == S[j]) continue;
      --ans;
    }
  }
 
  cout<<ans;
  return 0;
    
}