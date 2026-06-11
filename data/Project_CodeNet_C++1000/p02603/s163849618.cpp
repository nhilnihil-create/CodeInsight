// D - Road to Millionaire
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rp(i,s,e) for(int i=(int)(s);i<(int)(e);++i)

int main(){
	int N; cin>>N;
	vector<int> A(N+1, 0);
	rp(i, 1, N+1) cin>>A[i];
	vector<ll> dp_stock(N+1, 0);
	vector<ll> dp_yen(N+1, 0);
	dp_yen[0] = 1000;
	rp(day, 1, N+1){
		dp_stock[day] = max(dp_stock[day-1], dp_yen[day-1]/A[day]);
		ll sell = dp_yen[day-1] + dp_stock[day-1] * (A[day] - A[day-1]);
		dp_yen[day] = max(dp_yen[day-1], sell);
	}
	cout<< dp_yen[N] <<endl;
}
