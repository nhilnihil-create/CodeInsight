#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int n;
  	cin >> n;
  	
  	double base = 1.0 / n;
  	double ans = 0;
	rep(i, n+1) if(i%2 == 1) ans += base;
  	printf("%f\n", ans);
}