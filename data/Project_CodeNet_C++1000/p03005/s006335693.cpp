#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {

	int n, ball;
	cin >> ball >> n;

	ball -= n;

	if (n == 1)
		cout << 0;
	else
		cout << ball;
	cout << endl;

	return 0;
}