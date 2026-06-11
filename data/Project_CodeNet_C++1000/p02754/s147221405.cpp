#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	LL N;
	cin >> N;
	LL A, B;
	cin >> A >> B;
	LL ans = 0;
	LL tmp = 0;
	tmp = N / (A + B);
	ans += tmp * A;
	tmp = N - tmp * (A + B);
	if(tmp >= A) ans += A;
	else ans += tmp;
	cout << ans << endl;

}










