#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
	int N;
	cin >> N;

	vector<int> P(N);
	rep(i,N) cin >> P.at(i);

	int tmp = 200001,ans=0;
	rep(i,N){
		if(P.at(i) < tmp){
			ans++;
			tmp = P.at(i);
		}
	}

	cout << ans << endl;
}
