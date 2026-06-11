#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, m;
	cin >> a >> b >> m;
	vector<int> ap(a);
	for (int i = 0; i < a; i++)cin >> ap.at(i);
	vector<int> bp(b);
	for (int i = 0; i < b; i++)cin >> bp.at(i);
	vector<vector<int>> w(m, vector<int>(3));
	for (int i = 0; i < m; i++) {
		cin >> w.at(i).at(0) >> w.at(i).at(1) >> w.at(i).at(2);
	}

	//暫定 = ap最小+bp最小
	int a_min = 100000;
	for (int i = 0; i < a; i++) a_min = min(a_min, ap.at(i));
	int b_min = 100000;
	for (int i = 0; i < b; i++)b_min = min(b_min, bp.at(i));
	int res = a_min + b_min;
	//割引券で暫定より低くなる可能性:mで検索
	for (int i = 0; i < m; i++) {
		int aw = w.at(i).at(0);
		int bw = w.at(i).at(1);
		int c = w.at(i).at(2);
		int wari = ap.at(aw-1) + bp.at(bw-1) - c;
		res = min(res, wari);
	}
	cout << res << endl;
}