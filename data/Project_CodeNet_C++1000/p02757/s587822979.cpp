// E - Divisible Substring
#include <bits/stdc++.h>
using namespace std;
#define c2d(c) ((c)-'0') // char to digit

int main() {
	int N,P; string S; cin>>N>>P>>S;
	long long total = 0;
	if(10%P == 0){ // P={2,5}
		for(int i=0; i<N; ++i)
			if(c2d(S[i]) % P == 0) total += i+1;
	}
	else{
		reverse(S.begin(), S.end());
		vector<int> cnt(P, 0);
		int r = 0, ten = 1;
		cnt[r]++; // for half-open section
		for(char si:S){
			// n=count(r), nC2 = {n-1}C2 + {n-1}
			// {n-1} = count(r): previous of count up
			// ∴ total = total + {count of previous of count up}
			r = (r + c2d(si)*ten) % P;
			total += cnt[r];
			cnt[r]++;
			ten = ten * 10 % P;
		}
	}
	cout << total << endl;
}