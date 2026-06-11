#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <climits>
#include <cfloat>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> p(n);
	int ans = 1;
	for(int i=0;i<n;i++){
		cin >> p.at(i);
	}
	int m = p.at(0);
	for(int i=1;i<n;i++){
		if(m > p.at(i)){
			ans++;
			m = p.at(i);
		}
	}
	cout << ans << endl;
	return 0;
}