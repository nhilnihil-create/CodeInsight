#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	LL N; cin >> N;
	LL ans = N;
	for(LL i = 1; i * i <= N; ++i){
		LL tmp;
		if(N % i == 0) tmp = i + N / i - 2;
		ans = min(ans, tmp);
	}
	cout << ans << endl;
}













