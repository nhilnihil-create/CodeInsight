#include<iostream>
#include<algorithm>
using namespace std;
int p[200000];

int main() {


	//A
	string s, t;
	int a, b;
	string u;
	cin >> s >> t;
	cin >> a >> b;
	cin >> u;
	if (s == u) {
		a--;
	}
	else {
		b--;
	}
	cout << a << ' '<< b << endl;
	return 0;

	//B
	/*string s;
	cin >> s;
	int i;
	for (i = 0; i < s.size(); i++) {
		s[i] = 'x';
	}
	cout << s << endl;
	return 0;*/

	//C
	/*int n;
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p, p + n);
	for (i = 0; i < n-1; i++) {
		if (p[i] == p[i + 1]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;*/
	//D
	/*int n, k;
	cin >> n >> k;
	int i;
	for (i = 0; i < n; i++) {
		cin >> p[i];
	}
	int max = 0;
	int sum = 0;
	for (i = 0; i < k; i++) {
		sum = sum + p[i];
	}
	max = sum;
	for (i = k; i < n; i++) {
		sum = sum + p[i] - p[i - k];
		if (sum > max)max = sum;
	}
	//cout << max + k << endl;
	double f = (double)(((double)max +(double) k) / 2);
	printf("%.10f\n", f);
	//cout << (max + k) / 2 << endl;
	return 0;
	*/
}