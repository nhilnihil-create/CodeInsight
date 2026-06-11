#include <bits/stdc++.h>
using namespace std;

int N, Q, b, c;
long long sum;
const int k = 1e5+5;
int arr[k], cnt[k];

int main() {
	
	ios_base::sync_with_stdio(false);
	sum = 0;
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
		sum += arr[i];
	}
	cin >> Q;
	for(int i = 0; i < Q; i++) {
		cin >> b >> c;
		sum += (c-b)*cnt[b];
		cout << sum << "\n";
		cnt[c] += cnt[b];
		cnt[b] = 0;
	}
}