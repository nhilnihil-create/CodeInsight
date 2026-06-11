#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int n;
int Arr[N];
int L[N][2], R[N][2];
ll ans;
vector <int> vec1, vec2, add;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> Arr[i];

	for (int i = 0; i < n; i++) {
		L[i][0] = L[i][1] = -1;

		while (vec2.size() && Arr[vec2.back()] < Arr[i])
			vec2.pop_back();
		if (vec2.size())
			L[i][1] = max(L[i][1], vec2.back());


		while (vec1.size() && Arr[vec1.back()] < Arr[i]) {
			add.push_back(vec1.back());
			vec1.pop_back();
		}

		while (add.size()) {
			while (vec2.size() && Arr[vec2.back()] < Arr[add.back()])
				vec2.pop_back();

			vec2.push_back(add.back());
			add.pop_back();
		}

		if (vec1.size()) {
			L[i][0] = vec1.back();
			if (1 < vec1.size())
				L[i][1] = max(L[i][1], vec1[vec1.size() - 2]);
		}
		vec1.push_back(i);
	}

	// for (int i = 0; i < n; i++)
	// 	cout << L[i][0] << " " << L[i][1] << "\n";
	vec1.clear();
	vec2.clear();
	add.clear();

	for (int i = n - 1; ~i; i--) {
		R[i][0] = R[i][1] = -1;

		while (vec2.size() && Arr[vec2.back()] < Arr[i])
			vec2.pop_back();
		if (vec2.size())
			R[i][1] = (R[i][1] == -1? vec2.back(): min(R[i][1], vec2.back()));


		while (vec1.size() && Arr[vec1.back()] < Arr[i]) {
			add.push_back(vec1.back());
			vec1.pop_back();
		}

		while (add.size()) {
			while (vec2.size() && Arr[vec2.back()] < Arr[add.back()])
				vec2.pop_back();

			vec2.push_back(add.back());
			add.pop_back();
		}

		if (vec1.size()) {
			R[i][0] = vec1.back();
			if (1 < vec1.size())
				R[i][1] = (R[i][1] == -1? vec1[vec1.size() - 2]: min(R[i][1], vec1[vec1.size() - 2]));
		}
		vec1.push_back(i);
	}

	for (int i = 0; i < n; i++) {
		ll l, r;
		if (L[i][0] != -1) {
			l = L[i][1] + 1;
			r = R[i][0] - 1;
			if (R[i][0] == -1)
				r = n - 1;

			ans += (L[i][0] - l + 1) * (r - i + 1) * Arr[i];
		}
		if (R[i][0] != -1) {
			l = L[i][0] + 1;
			r = R[i][1] - 1;
			if (R[i][1] == -1)
				r = n - 1;

			ans += (i - l + 1) * (r - R[i][0] + 1) * Arr[i];
		}
	}


	// for (int i = 0; i < n; i++) {
	// 	vector <int> vv;
	// 	vv.push_back(Arr[i]);
	// 	for (int j = i + 1; j < n; j++) {
	// 		vv.push_back(Arr[j]);
	// 		sort(vv.begin(), vv.end());
	// 		ans -= vv[vv.size() - 2];
	// 	}
	// }
	cout << ans << "\n";
	return 0;
}