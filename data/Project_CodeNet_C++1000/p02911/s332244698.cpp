#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	ll K;
	int Q;
	cin >> N >> K >> Q;
	int score[N+1];
	rep(i,N) score[i+1] = K-Q;
	rep(i,Q) {
		int tmp;
		cin >> tmp;
		score[tmp]++;
	}
	rep(i,N) {
		if (score[i+1]>0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
		return 0;
}
