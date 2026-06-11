#include <bits/stdc++.h>
using namespace std;
typedef complex<double> Pos;

void Koch(vector<Pos>& v) {
	vector<Pos> res;
	Pos s(1.0 / 3, 0), u(0.5, sqrt(3.0) / 6), t(2.0 / 3, 0);

	res.push_back(v[0]);
	for (size_t i = 1; i < v.size(); i++) {
		Pos sta = v[i - 1], vec = v[i] - v[i - 1];
		res.push_back(sta + vec * s);
		res.push_back(sta + vec * u);
		res.push_back(sta + vec * t);
		res.push_back(sta + vec);
	}
	v = res;
}

int main()
{
	int n;
	vector<Pos> v;
	v.push_back(Pos(0, 0));
	v.push_back(Pos(100, 0));
	cin >> n;
	while (n--) {
		Koch(v);
	}
	for_each(v.begin(), v.end(), [](const Pos& p) {
		cout << fixed << setprecision(5) << p.real() << ' ' << p.imag() << endl;
	});
	return 0;
}