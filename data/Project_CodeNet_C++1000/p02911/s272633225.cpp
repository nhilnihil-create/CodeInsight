#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n, k, q;
  cin >> n >> k >> q;

  vi score(n,k-q);
  rep(i,q){
    int ai;
    cin >> ai;
    score.at(ai-1)++;
  }

  rep(i,n) cout << (score.at(i) > 0 ? "Yes" : "No") << endl;
  return 0;
}
