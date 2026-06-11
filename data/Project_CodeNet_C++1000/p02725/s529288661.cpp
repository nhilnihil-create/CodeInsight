#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;

int main () {
	int N, K;
	vector <int> v, d;
	cin >> K >> N;
	for (int i=0; i<N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back (tmp);
	}
	sort (v.begin(), v.end());
	for (int i=0; i<N-1; i++) {
		d.push_back (v[i+1]-v[i]);
	}
	d.push_back (v[0]+K-v[N-1]);
	sort (d.rbegin(), d.rend());
	cout << (K-d[0]) << endl;
	return 0;
}