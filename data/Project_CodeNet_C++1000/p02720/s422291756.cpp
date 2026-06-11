#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int max_keta;
int k;

void dfs( int digit, int keta, ll val ){
	if ( k < 0 )
		return;
	val = val * 10 + digit;
	
	keta++;
	if ( keta == max_keta ){
		if ( --k == 0 ){
			cout << val << endl;
		}
		return;
	}
	else {
		if ( digit != 0 ){
			dfs(digit-1, keta, val);
		}
		dfs(digit, keta, val);
		if ( digit != 9 ){
			dfs(digit+1, keta, val);
		}
	}
}

int main(){
	cin >> k;
	for ( max_keta = 1; ; max_keta++ ){
		for ( int i = 1; i <= 9; i++ ){
			dfs(i, 0, 0);
			if ( k < 0 )
				return 0;
		}
	}
}


