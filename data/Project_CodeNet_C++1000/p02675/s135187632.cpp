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
	int a = n%10;
	if(a == 3){
		cout << "bon" << endl;
	}else if(a == 0||a == 1||a == 6||a == 8){
		cout << "pon" << endl;
	}else{
		cout << "hon" << endl;
	}
	return 0;
}