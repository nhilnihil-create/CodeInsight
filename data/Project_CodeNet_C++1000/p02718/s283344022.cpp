#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 100;
const int INF = 1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L

int main() {
	int N, M; cin >> N >> M;
	priority_queue<int> PQ;
	int sum = 0;
	rep(i,N) {
		int temp;
		cin >> temp;
		PQ.push(temp);
		sum += temp;
	}
	rep(i,M) {
		int temp = PQ.top(); PQ.pop();
		double tmp2 = (double)sum / (double)(4*M);
		if ( (double)temp < tmp2 ) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}