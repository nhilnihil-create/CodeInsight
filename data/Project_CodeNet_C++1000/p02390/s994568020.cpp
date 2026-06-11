#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <functional>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main(){
	int h, m, s, A;
	cin >> A;

	h = A / 3600;
	m = (A - h * 3600) / 60;
	s = A % 60;

	cout << h << ":" << m << ":" << s << endl;
	return 0;
}