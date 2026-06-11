#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int H[N+1];
  int G[N+1];
  for (int i=1; i<N+1; i++){
    cin >> H[i];
  }
  for (int i=1; i<N+1; i++){
    G[i]=1;
  }
  for (int i=0; i<M; i++){
    int a,b;
    cin >> a >> b;
    if (H[a]>=H[b])
      G[b]=0;
    if (H[b]>=H[a])
      G[a]=0;
  }
  int ans=0;
  for (int i=1; i<N+1; i++){
    ans+=G[i];
  }
  cout << ans << endl;
}