#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 1000006;
bool isp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x;
    cin >> x;
    isp[0] = isp[1] = true;
    for (int i = 2; i * i < N; i++) {
		if (isp[i] == false) {
			for (int j = i * i; j < N; j += i) {
				isp[j] = true;
			}
		}
	}
	for (; x < N; x++) {
		if (!isp[x]) {
			break;
		}
	}
	cout << x;
    return 0;
}
