#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void swap(int a,int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	int n,k,c;
	cin >> n>>k>>c;
	string s;
	cin >> s;

	vector<int>a(n);
	vector<int>b(n);

	int count = 0;
	int day = 0;

	while (count != k) {
		if (s[day]=='o') {
			a[count] = day;
			count++;
			day += c + 1;
		}
		else {
			day++;
		}
	}

	count = 0;
	day = n-1;

	while (count != k) {
		if (s[day] == 'o') {
			b[k-count-1] = day;
			count++;
			day -= c + 1;
		}
		else {
			day--;
		}
	}

	for (int i = 0; i < k;i++) {
		if (a[i]==b[i]) {
		cout << a[i]+1 << endl;
		}
	}


	return 0;
}