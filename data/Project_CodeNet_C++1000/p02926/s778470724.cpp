#include <iostream>
#include <iomanip>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	cout << fixed << setprecision(15);
	int N;
	cin >> N;
	vector<tuple<long double, long double, long double>> V(N);
	for (int i = 0; i < N; i++){
		int x, y;
		cin >> x >> y;
		V[i] = make_tuple(atan2(y, x), y, x);
	}
	sort(V.begin(), V.end());
	double ans = 0;
	for (int i = 0; i < N; i++){
		for (int j = i; j < N; j++){
			double y = 0;
			double x = 0;
			for (int k = i; k <= j; k++){
				y += get<1>(V[k]);
				x += get<2>(V[k]);
			}
			ans = max(ans, hypot(x, y));
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = i; j < N; j++){
			double y = 0;
			double x = 0;
			for (int k = 0; k < i; k++){
				y += get<1>(V[k]);
				x += get<2>(V[k]);
			}
			for (int k = j; k < N; k++){
				y += get<1>(V[k]);
				x += get<2>(V[k]);
			}
			ans = max(ans, hypot(x, y));
		}
	}
	cout << ans << endl;
}