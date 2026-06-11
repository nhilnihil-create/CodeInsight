#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(),a.end());
  int answer = 0;
  for (int i = 1; i <= 100000; i++) {
    int itr = upper_bound(a.begin(),a.end(),i) - a.begin();
    if(itr == n/2) answer++;
  }
  cout << answer << '\n';
}
