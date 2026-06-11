// E - Divisible Substring
#include <bits/stdc++.h>
using namespace std;
#define c2d(c) ((c)-'0') // char to digit
#define modadd(x,y,m) x=(x+(y))%(m)
#define modmul(x,y,m) x=(x*(y))%(m)

int main(){
	int N,P; string S; cin>>N>>P>>S;
	long long total = 0;
	if(10%P == 0){ // P={2,5}
		for(int i=0; i<N; ++i) if(c2d(S[i]) % P == 0) total += i+1;
	}
	else{
		vector<int> cnt(P, 0);
		int r = 0, ten = 1;
		for(int i=N-1; i>=0; --i){
			cnt[r]++;
			modadd(r, c2d(S[i])*ten, P);
			total += cnt[r];
			modmul(ten, 10, P);
		}
	}
	cout << total << endl;
}