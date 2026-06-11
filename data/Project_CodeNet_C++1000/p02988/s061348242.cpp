#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, cnt = 0;
  cin >> n;
  vector<int> v(n);
  rep(i, n){
  	cin >> v.at(i);
  }
  for(int i = 1; i <= n-2; i++){
  	int max_n = max(v[i-1], max(v[i], v[i+1]));
    int min_n = min(v[i-1], min(v[i], v[i+1]));
    if(v[i] != max_n && v[i] != min_n){
    	cnt++;
    }
  }
  cout << cnt << endl;
  return 0; 
}