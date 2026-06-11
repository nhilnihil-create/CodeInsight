#include <bits/stdc++.h>

using namespace std;

inline int ctoi(char c) { if(c < '0' || '9' < c) throw invalid_argument("ctoi error"); return c - '0'; }
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

template <typename T>
inline T gcd(T x, T y){
	if (x <= 0 || y <= 0) throw invalid_argument("gcd error: x <= 0 or y <= 0");
	
	if(x < y) swap(x, y);
	T r = x % y;

	while(r != 0){
		x = y;
		y = r;
		r = x % y;
	}

	return y;
}
template <typename T>
inline T lcm(T x, T y){
	if (x <= 0 || y <= 0) throw invalid_argument("lcm error: x <= 0 or y <= 0");

	return x * y / gcd(x, y);
}

int n;
vector<vector<int>> test;

void func(vector<int> v){
	if(v.size() == n){
		test.push_back(v);
	}

	vector<bool> num(n, false);
	rep(i, v.size()){
		num[v[i]] = true;
	}
	
	rep(i, num.size()){
		if(!num[i]){
			vector<int> t = v;
			t.push_back(i);
			func(t);
		}
	}
}

int main(){
	cin >> n;

	vector<pair<double, double>> input(n);
	rep(i, n){
		cin >> input[i].first >> input[i].second;
	}

	rep(i, n){
		vector<int> v;
		v.push_back(i);
		func(v);
	}

	double ans = 0;
	rep(i, test.size()){
		rep(j, n - 1){
			double x = input[test[i][j + 1]].first - input[test[i][j]].first;
			double y = input[test[i][j + 1]].second - input[test[i][j]].second;
			ans += sqrt(x * x + y * y);
		}
	}

	printf("%.10f", ans / (double)test.size());

	return 0;
}