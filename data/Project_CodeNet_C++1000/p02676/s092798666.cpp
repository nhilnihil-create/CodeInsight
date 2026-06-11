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
	string s;
	int k;
	cin >> k >> s;
	if(s.size() <= k){
		cout << s << endl;
	}else{
		cout << s.substr(0,k) << "..." << endl;
	}
	return 0;
}