#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

long long N;
long long P[200005];
int main(){
	cin >> N;
	rep(i, N) cin >> P[i];

	long long mini = LONG_MAX;
	long long ans = 0;

	rep(i, N) {
		if(mini >= P[i]) {
			ans++;
		}
		mini = min(mini, P[i]);
	}
	cout << ans << endl;
}