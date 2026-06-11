#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

int MOD=1000000007;

int main() {
  int N,ans=0;
  cin >> N;
  string s[N+10],X;
  int t[N+10];
  for(int i=0; i<N; i++) cin >> s[i] >> t[i];
  cin >> X;
  for(int i=N-1; i>=0; i--){
    if(X==s[i]) break;
    ans+=t[i];
  }
  cout << ans << endl;
}