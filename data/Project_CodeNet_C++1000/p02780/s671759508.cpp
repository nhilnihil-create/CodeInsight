#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
	int n, k;
  	cin >> n >> k;
  	vector<int> p(n), s(n+1);
  	rep(i, n){
		cin >> p[i];
      	p[i]++; //期待値(p+1)/2なのでp+1で持っておく。最後で割る
    }

  	s[0] = 0;
  	for(int i = 1; i < n+1; i++){
    	s[i] = s[i-1]+p[i-1];
    }
  	
  	int x = 0;
  	rep(i, n+1-k){  	
    	x = max(x, s[i+k]-s[i]);
    }
  
  	double ans = x / 2.0;
  	printf("%.10f", ans);
}