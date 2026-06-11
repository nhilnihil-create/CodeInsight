#include <bits/stdc++.h>

using namespace std;

int main() {

	while (1) {
		int n;
		cin >> n;

		if (n == 0) { return 0; }

		vector<struct tm> tms(n);
		vector<struct tm> tme(n);

		string in1, in2;

		vector<int> jikoku(86401);

		for (int i = 0; i < n; i++) {
			cin >> in1 >> in2;

			tms[i].tm_year = 70;
			tms[i].tm_mon = 0;
			tms[i].tm_mday = 1;
			tms[i].tm_hour = stoi(in1.substr(0, 2)) + 9;
			tms[i].tm_min = stoi(in1.substr(3, 2));
			tms[i].tm_sec = stoi(in1.substr(6, 2));

			tme[i].tm_year = 70;
			tme[i].tm_mon = 0;
			tme[i].tm_mday = 1;
			tme[i].tm_hour = stoi(in2.substr(0, 2)) + 9;
			tme[i].tm_min = stoi(in2.substr(3, 2));
			tme[i].tm_sec = stoi(in2.substr(6, 2));


			jikoku[mktime(&tms[i])]++;
			jikoku[mktime(&tme[i])]--;

		}

		int res = 0;
		int resmax = 0;
		for (int i = 0; i < 86401; i++) {
			res += jikoku[i];
			resmax = max(resmax, res);
		}

		cout << resmax << endl;
	}
	return 0;
}
