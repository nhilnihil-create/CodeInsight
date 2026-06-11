#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll N;
ll A[200000];



int main(){
	cin >> N;
	
	ll all_xor = 0;
	for ( int i = 0; i < N; i++ ){
		cin >> A[i];
		all_xor ^= A[i];
	}
	
	/*
		評価値 = Axor + Bxor
		       = Axor + (all_xor ^ Axor)
		all_xor のビットが1になっている部分は、評価に影響しない
		all_xor のビットが0になっている部分は、できるだけ1にしたい
		Axor & ~all_xor を最大化する
		
		Axorを探すときに、(a0, a1, a2, a3...) の中から選ぶのと、(a0, a1^a0, a2, a3... )の中から選ぶのは同じことである
	*/
	ll Axor = 0;
	for ( int b = 59; b >= 0; b-- ){
		ll m = (1LL) << b;
		if ( all_xor & m )
			continue;
		
		for ( int i = 0; i < N; i++ ){
			if ( A[i] & m ){
				ll tmp = A[i];
				if ( (Axor & m) == 0 )
					Axor ^= tmp;
				
				for ( int j = 0; j < N; j++ )
					if ( A[j] & m )
						A[j] ^= tmp;
				
				break;
			}
		}
	}
	
	cout << (Axor + (all_xor^Axor)) << endl;
	return 0;
}
