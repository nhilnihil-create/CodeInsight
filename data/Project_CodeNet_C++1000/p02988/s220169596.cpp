#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
int n;
cin >> n;
vector<int> a(n);

rep(i,n) cin >> a.at(i);

int cnt = 0;
for(int i = 1; i < n-1; i++){
  vector<int> b = {a.at(i-1),a.at(i),a.at(i+1)};
  sort(b.begin(),b.end());
  if(b.at(1) == a.at(i)) cnt++;
}

cout << cnt << endl;
}
  
