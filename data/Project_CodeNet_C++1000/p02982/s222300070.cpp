#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	int x[n][d];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < d; j++){
			cin >> x[i][j];
		}
	}
	int out = 0;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			double distance = 0;
			for(int k = 0; k < d; k++){
				distance += abs(x[i][k] - x[j][k]) * abs(x[i][k] - x[j][k]);
			}
			if((int)sqrt(distance) == sqrt(distance)) out++;
		}
	}
	cout << out << endl;
}
