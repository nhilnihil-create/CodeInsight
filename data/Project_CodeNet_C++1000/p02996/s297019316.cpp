#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<pair<int,int>> p(n);
  rep(i,n) cin >> p[i].second >> p[i].first;
  sort(p.begin(), p.end());


  int sum = 0;
  rep(i,n){
    sum += p[i].second;
    if(sum > p[i].first) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}