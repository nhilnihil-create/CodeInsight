#include <iostream>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <vector>
#include <functional>
using namespace std;

int n;
vector<int> v;
int main(){
	cin >> n;

	for (int i = 0; i < n; ++i){
		int buf;
		cin >> buf;
		v.push_back(buf);
	}

	//sort(v.begin(), v.end(), greater<int>());

	vector<int>::reverse_iterator it, end;
	for (it = v.rbegin(), end = v.rend(); it != end;++it){
		if (it == v.rbegin())
			cout << (*it);
		else
			cout << " " << (*it);
	}
	cout << endl;

	return 0;
}