#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 1000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L

int main() {
	int N; cin >> N;
	vector<int> L;

	rep(i,N) {
		int temp; cin >> temp;
		L.push_back(temp);
	}
	sort(L.begin(),L.end());
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if(L[i]==L[j] || L[j]==L[k] || L[k]==L[i]) continue;
				if((L[i]+L[j]<=L[k])||(L[j]+L[k]<=L[i])||(L[k]+L[i]<=L[j])) {
					continue;
				}
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}