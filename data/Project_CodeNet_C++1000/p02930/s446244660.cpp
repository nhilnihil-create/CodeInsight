#include <iostream>
using namespace std;

int ans[510][510];

void solve(int s, int g, int c){
	int num=(g-s)/2;
	if(num>0){
		for(int i=s; i<s+num; ++i){
			for(int j=s+num; j<g; ++j){
				ans[i][j]=c;
			}
		}
		solve(s, s+num, c+1);
		solve(s+num, g, c+1);
	}
}

int main() {
	int N;
	cin >> N;
	solve(1, N+1, 1);
	for(int i=1; i<N; ++i){
		cout << ans[i][i+1];
		for(int j=i+2; j<=N; ++j) cout << ' ' << ans[i][j];
		cout << endl;
	}
	return 0;
}