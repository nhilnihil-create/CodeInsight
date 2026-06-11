#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> V(N,-1);
  int s, c, ans=0;
  
  for (int i=0; i<M; i++) {
    cin >> s >> c;
    if (s==1 && c==0) {
      if (N==1) {
        V[s-1]=c;
        continue;
      }
      ans=-1;
      break;
    }
    if (V[s-1]!=-1 && V[s-1]!=c) {
      ans=-1;
      break;
    }
    V[s-1]=c;
  }
  if (V[0]==-1 && N==1) {V[0]=0;}
  else if (V[0]==-1) {V[0]=1;}
  if (ans==-1) {cout << ans << endl;}
  else {
    for (int i=0; i<N; i++) {
      if (V[i]==-1) {V[i]=0;}
      cout << V[i];
    }
    cout << endl;
  }
}