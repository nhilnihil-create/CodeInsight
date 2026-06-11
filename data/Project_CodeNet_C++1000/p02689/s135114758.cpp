#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main(){
  int N, M; cin >> N >> M;
  vi H(N+1,0); rep2(i,1,N+1) cin >> H[i];
  vvi rt(N+1, vi());
  rep(i,M){
    int a, b; cin >> a >> b;
    rt[a].push_back(b);
    rt[b].push_back(a);
  }
  
  int count = 0;
  rep2(i,1,N+1){
    int maxH = H[i];
    bool highest = true;
    for(int x : rt[i]){
       if(maxH <= H[x]) highest = false;
    }
    if(highest)count++;
  }
  cout << count << endl;  
  return 0;
}