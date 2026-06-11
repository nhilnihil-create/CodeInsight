#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <math.h>
#include <stdio.h>
using namespace std;

int main(){
	int n, m;
	while(cin>> n >> m, n || m){
		vector<int> p_freq(11);
		for(int i = 0; i < n; i++) {
			int d, p;
			cin >> d >> p;
			p_freq[p] += d;
		}
		
		int count = 0;
		for(int i = 10; i > 0; i--) {
			if(m >= p_freq[i])
				m -= p_freq[i];
			else {
				count += (p_freq[i] - m) * i;
				m = 0;
			}
		}
		cout << count << endl;
	}
	return 0;
}