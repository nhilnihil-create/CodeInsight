#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int n;
  	cin >> n;
  	double ans = 0.0, a;
  	
  	rep(i, n){
      	cin >> a;
      	ans += 1.0 / a;
    }
  	ans = 1.0 / ans;
  
  	printf("%f", ans);
}