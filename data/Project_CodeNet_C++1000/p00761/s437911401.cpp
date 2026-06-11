#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> S;
	int temp[100];

	int a, L, min, max;
	while (1){
		int ssize = 1;
		bool FLAG = false;
		cin >> a >> L;
		if (!a && !L) break;
		if (a == 0){
			cout << " " << a << " " << a << " " << a + 1 << endl;
			return 0;
		}
		temp[0] = a;
		for (int i = 0; i < 100; ++i){

			for (int l = 0; l < L; ++l){
				S.push_back(a % 10);
				a = a / 10;
			}
			sort(S.begin(), S.end());
			int digit = 1;
			min = 0;
			max = 0;
			for (int j = 0; j < L; ++j){
				max += S[j] * digit;
				min += S[L - j - 1] * digit;
				digit *= 10;
			}
			//cout << max << " " << min << endl;
			for (int m = 0; m < ssize; ++m){
				if (max - min == temp[m]){
					cout << m << " " << max - min << " " << i - m + 1 << endl;
					FLAG = true;
					break;
				}
			}
			if (FLAG)break;
			temp[ssize] = max - min;
			++ssize;
			a = max - min;
			//cout << "a" << a << endl;
			S.clear();
		}
		S.clear();
	}

	return 0;
}