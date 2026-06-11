#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int N;
	cin >> N;

	vector<int64_t> H(N);
	rep(i, N) cin >> H.at(i);
	reverse(H.begin(), H.end());
	rep2(i, N, 1, 1){
		if (H.at(i - 1) == H.at(i) - 1) H.at(i)--;
		else if (H.at(i - 1) < H.at(i)){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}