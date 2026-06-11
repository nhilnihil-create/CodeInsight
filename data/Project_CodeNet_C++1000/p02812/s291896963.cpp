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
	vector<char> arr(n);

	for (int i = 0; i < n; i++)cin>>arr[i];

	int count = 0;
	for (int i = 0; i < n - 2; i++) {
		if (arr[i] == 'A') {
			if (arr[i + 1] == 'B') {
				if (arr[i + 2] == 'C')
					count++;
			}
		}
	}

	cout << count << endl;

	return 0;
}