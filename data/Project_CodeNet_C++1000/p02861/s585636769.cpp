#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int n;
  	cin >> n;
  	vector<int> x(n), y(n);
  	rep(i, n) cin >> x[i] >> y[i];
  
  	auto dist = [&](int i, int j){
    	double dx = x[i] - x[j];
      	double dy = y[i] - y[j];
      	return sqrt(dx * dx + dy * dy);
    };
  
	double len = 0;
  	rep(i, n)rep(j, i){
    	len += dist(i, j);
    }
  	double ans = len * 2 / n;
  	printf("%.10f\n", ans);
}