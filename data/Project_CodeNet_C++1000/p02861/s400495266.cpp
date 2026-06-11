#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, mult = 1, di; cin >> n;
  for (int i = 1; i <= n-2; ++i) mult *= i;
  di = mult*n*(n-1);
  mult *= 2*(n-1);
//  cout << mult << " " << di << "\n";
  vector <pair<int,int>> coord(n);
  for (int i = 0; i < n; ++i){
	cin >> coord[i].first >> coord[i].second;
  }
  double ans = 0;
  for (int i = 0; i < n; ++i){
	for (int j = i; j < n; ++j){
			int x = coord[i].first - coord[j].first;
			int y = coord[i].second - coord[j].second;	
			ans += mult*sqrt(x*x + y*y);
	}
  }
	cout << fixed << setprecision(9) << ans/di << "\n"; 
return 0;
}
