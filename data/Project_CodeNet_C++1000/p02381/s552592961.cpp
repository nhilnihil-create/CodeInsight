#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	int n;
	cout << fixed << setprecision(8);
	while (cin >> n, n != 0){
		vector<int> s(n);
		int sum = 0;
		for (int i = 0; i < n; i++){
			cin >> s[i];
			sum += s[i];
		}
		double av = (double)sum / n;
		double sigma = 0.0;
		for (int i = 0; i < n; i++){
			sigma += (s[i] - av) * (s[i] - av);
		}
		cout << sqrt(sigma / n) << endl;
	}
}
