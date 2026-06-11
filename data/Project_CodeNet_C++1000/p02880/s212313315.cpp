#include <bits/stdc++.h>
using namespace std;

int N, cnt = 0;

int main () {
	cin >> N;
	for (int i = 1; i <= 9; i++){
		for (int j = 1; j <= 9; j++){
			if (N == i*j){
				cnt++;
			} else if (N == i*i || N == j*j){
				cnt = cnt + 2;
			}
		}
	}
	if (cnt > 1){
		cout << "Yes";
	} else {
		cout << "No";
	}
}