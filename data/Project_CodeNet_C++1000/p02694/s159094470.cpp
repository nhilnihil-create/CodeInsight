#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	long long X;
	cin >> X;
	long long money = 100;
	int N = 0;
	while (money < X) {
		money = money + money / 100;
		N++;
	}
	cout << N << endl;
}