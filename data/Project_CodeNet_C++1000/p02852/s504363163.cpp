#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N, M;
string S;

int main(){
	cin >> N >> M;
	cin >> S;


	vector<long long> ans;
	long long cur = N;

	while(cur > 0) {
		bool ng = true;
		for(long long len = M; len > 0; len--) {
			if(cur - len >= 0 && S[cur - len] == '0') {
				cur -= len;
				ans.push_back(len);
				ng = false;
				break;
			}
		}
		if(ng) {
			cout << -1 << endl;
			return 0;
		}
	}

	for(long long i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
		if(i != 0) {
			cout << " ";
		} else {
			cout << endl;
		}
	}
}