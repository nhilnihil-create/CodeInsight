#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
using namespace std;
#define ll long long
int main(){

	double B;
	ll A;
	cin >> A >> B;

	ll iB=(B * 100)+0.5;
	A *= iB;
	A /= 100;
	cout << A << endl;

	return 0;
}