// E - Divisible Substring
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define c2d(c) ((c)-'0') // char to digit

int main() {
	int N,P; string S; cin>>N>>P>>S;
	ll total = 0;
	if(P==2 || P==5){
		rep(i, N) if(c2d(S[N-1-i]) % P == 0) total += N - i;
	}
	else{
		reverse(S.begin(), S.end());
		int r = 0, ten = 1;
		vector<int> cnt(P, 0);
		cnt[r]++;
		rp(i, 1, N+1) {
			// n=count(r), nC2 = {n-1}C2 + {n-1}
			// {n-1} = count(r): previous of count up
			// ∴ total = total + {count of previous of count up}
			r = (r + c2d(S[i-1])*ten) % P;
			total += cnt[r];
			cnt[r]++;
			ten = ten * 10 % P;
		}
	}
	cout << total << endl;
}
