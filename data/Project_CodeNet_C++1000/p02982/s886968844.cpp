#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int N, D;
	cin >> N >> D;

	vector<vector<int>> c(N, vector<int>(D));
	rep(i, N){
		rep(n, D) cin >> c.at(i).at(n);
	}
	int count = 0;
	rep(i, N){
		int n = i + 1;
		for(; n < N; n++){
			int sum = 0;
			rep(k, D){
				int a = max(c.at(i).at(k), c.at(n).at(k));
				int b = min(c.at(i).at(k), c.at(n).at(k));
				// cout << "i:" << i << " n:" << n << " " << a << "," << b << endl;
				sum += (a - b) * (a - b);
			}
			// cout << "sum = " << sum << endl;
			// cout << sqrt(sum) << " " << floor(sqrt(sum)) << endl;
			if (sqrt(sum) == floor(sqrt(sum))) count++;
		}
	}
	cout << count << endl;
}