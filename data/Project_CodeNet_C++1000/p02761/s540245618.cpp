#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll N,M,i;
  ll s[6];
  bool check = true;
  char c[6];
  char S[8];
  cin >> N >> M;
  for(i=0;i<=M-1;i++)
    cin >> s[i] >> c[i];
  for(i=0;i<=N-1;i++)
    S[i] = 'x';
  for(i=0;i<=M-1;i++){
    if(S[s[i]-1] == 'x') S[s[i]-1] = c[i];
    if(S[s[i]-1] != 'x' && S[s[i]-1] != c[i]) check = false;
    if(N >= 2 && s[i] == 1 && c[i] == '0') check = false;
    }
  for(i=0;i<=N-1;i++){
    if(S[i] == 'x' && i==0) S[i] = '1';
    if(S[i] == 'x' && i>0) S[i] = '0';
  }
  if(N==1 && M==0) S[0] = '0';
  if(check)
    for(i=0;i<=N-1;i++)
      cout << S[i];
  else cout << -1 << endl;
} 


