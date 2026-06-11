#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int N,K,S; cin >> N >> K >> S;
	int inf = 1e9;
	if (inf == S) {
		inf = 1;
	}

	for (int i = 0; i < N; i++) {
		if (i < K) {
			cout << S << " ";
		}else {
			cout << inf << " ";
		}
	}
	cout << endl;
	

	
	return 0;
}
