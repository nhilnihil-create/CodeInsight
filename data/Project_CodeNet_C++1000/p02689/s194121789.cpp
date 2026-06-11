#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  int N,M; cin >> N >> M;
  vector<ll> h(N);
  map<int,bool> m;
  for(int i = 0; i < N; i++){
    cin >> h[i];
    m[i] = true;
  }

  for(int i = 0; i < M; i++){
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    tmp1--; tmp2--;

    if(h[tmp1] <= h[tmp2]){
      m[tmp1] = false;
    }
    if(h[tmp2] <= h[tmp1]){
      m[tmp2] = false;
    }
  }

  int ans = 0;
  for(int i = 0; i < N; i++){
    if(m[i]) ans++;
  }
  cout << ans << endl;
}

