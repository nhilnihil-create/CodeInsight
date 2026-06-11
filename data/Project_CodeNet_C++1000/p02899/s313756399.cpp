#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vector<pair<int,int>> p(n);
  rep(i,n){
    cin >> p[i].first;
    p[i].second = i+1;
  }
  sort(p.begin(),p.end());
  rep(i,n) cout << p[i].second << " ";
}
