#include <bits/stdc++.h>
#define rep(i,a,n) for (int i = (a); i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i,0,n) cin >> p[i];
  sort(p.begin(),p.end());
  int sum = 0;
  rep(i,0,k) sum += p[i];
  cout << sum << endl;
  return 0;
}