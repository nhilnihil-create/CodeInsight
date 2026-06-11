#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0); 
  int n, m, d;
  cin >> n >> m;
  vector <pair<bool,int>> p(n);
  string s;
  int ca = 0, pen = 0;
  for (int i = 0; i < m; ++i){
	cin >> d >> s;
	--d;
	if (s == "WA" && p[d].first == false){
		++p[d].second;	
	}
	if (s == "AC" && p[d].first == false){
		p[d].first = true;
		pen += p[d].second;
		++ca;
	}	
  }
cout << ca << " " << pen << "\n"; 
return 0;
}
