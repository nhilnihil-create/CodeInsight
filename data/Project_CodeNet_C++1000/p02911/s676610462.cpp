#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n, k, q;
  cin >> n >> k >> q;
  vi score(n+1, k-q);
  rep(i,q){
    int a;
    cin >> a;
    score[a]++;
  }
  rep(i,n){
    if(score[i+1] > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
