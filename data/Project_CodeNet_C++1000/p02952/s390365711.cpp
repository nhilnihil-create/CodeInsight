#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>

using namespace std;


int main(){
	int n;
	cin >> n;

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		
		int h = i;
		int count = 0;

		while (1) {
			
			if (h == 0)break;

			h = h / 10;
			count++;

		}

		if (count % 2 == 1)ans++;

	}
	
	cout << ans << endl;

	return 0;
}