#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
const long long INF = 1LL << 60;

int main() {
  string S; cin>>S;
  int N=S.size();
  int ans=0;
  string old, now;
  for(int i=0; i<N; i++){
    now+=S[i];
    if(old == now)continue;
    old = now;
    now = "";
    ans++;
  }
  cout<<ans<<endl;
}
