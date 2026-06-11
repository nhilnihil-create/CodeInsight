#include<iostream>
#include<algorithm>

using namespace std;

using ll = long long;

int main() {
	int n, k;
	cin >> n >> k;
	int* p = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> p[i];
		p[i]--;
	}
	ll* c = new ll[n];
	for (int i = 0;i < n;i++) {
		cin >> c[i];
	}
	ll scoa = -1e9;
	int* arrived=new int[n];
	ll* t_scoa = new ll[n];
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			arrived[j] = -1;
			t_scoa[j] = -1e9;
		}
		int index = 1;
		arrived[i] = 0;
		arrived[p[i]] = 1;
		int now = p[i];
		t_scoa[now] = c[now];
		ll scoa_haba=0;
		int haba=0;
		for (;index < k;) {
			if (arrived[p[now]] == 0) {
				scoa_haba = t_scoa[now] + c[p[now]];
				haba = index + 1;
				now = p[now];
				break;
			}
			if (arrived[p[now]] > 0) {
				scoa_haba = t_scoa[now] - t_scoa[p[now]] + c[p[now]];
				haba = index - arrived[p[now]] + 1;
				now = p[now];
				break;
			}
			else {
				t_scoa[p[now]] = t_scoa[now] + c[p[now]];
				now = p[now];
				index++;
				arrived[now] = index;
			}
		}
		if (haba == 0) {

		}
		else {
			int start = now;
			while (1) {
				if (now == i) {
					t_scoa[now] = max(scoa_haba, scoa_haba * (ll)(k / haba));
				}
				else {
					t_scoa[now] = max(t_scoa[now], t_scoa[now] + scoa_haba * (ll)((k - arrived[now]) / haba));
				}
				now = p[now];
				if (now == start)break;
			}
		}
		for (int j = 0;j < n;j++) {
			scoa = max(scoa, t_scoa[j]);
		}
	}
	cout << scoa << endl;
}