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
	int n, m;
	cin >> n >> m;
	vector<int> a(n),pt(n);
	int ans = 0;
	int PT = 0;
	for(int i=0;i<n;i++){
		a.at(i) = 0;
		pt.at(i) = 0;
	}
	for(int i=0;i<m;i++){
		int p;
		string s;
		cin >> p >> s;
		if(!a.at(p-1) && s == "AC"){
			a.at(p-1) = 1;
		}
		if(!a.at(p-1) && s == "WA"){
			pt.at(p-1)++;
		}
	}
	for(int i=0;i<n;i++){
		if(a.at(i)){
			ans++;
			PT += pt.at(i);
		}
	}
	cout << ans << " " << PT << endl;
	return 0;
}