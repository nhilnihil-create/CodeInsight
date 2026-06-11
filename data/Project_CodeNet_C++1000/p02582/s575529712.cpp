#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  string S;cin>>S;
  if(S[0]=='S' && S[1]=='S' && S[2]=='S') cout << 0 << endl;
  if(S[0]=='R' && S[1]=='S' && S[2]=='S') cout << 1 << endl;
  if(S[0]=='S' && S[1]=='R' && S[2]=='S') cout << 1 << endl;
  if(S[0]=='S' && S[1]=='S' && S[2]=='R') cout << 1 << endl;
  if(S[0]=='R' && S[1]=='R' && S[2]=='S') cout << 2 << endl;
  if(S[0]=='R' && S[1]=='S' && S[2]=='R') cout << 1 << endl;
  if(S[0]=='S' && S[1]=='R' && S[2]=='R') cout << 2 << endl;
  if(S[0]=='R' && S[1]=='R' && S[2]=='R') cout << 3 << endl;
}
