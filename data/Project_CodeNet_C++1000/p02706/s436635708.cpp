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
	int sigma = 0;
	for(int i=0;i<m;i++){
		int a;
		cin >> a;
		sigma += a;
	}
	if(sigma > n){
		cout << -1 << endl;
	}else{
		cout << n-sigma << endl;
	}
	return 0;
}