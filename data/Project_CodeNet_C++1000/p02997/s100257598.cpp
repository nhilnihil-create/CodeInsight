#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll N, K;

int main(){
	cin >> N >> K;
	
	// 頂点1を他の全ての点とつなぐと、 Kmax=(N-1)(N-2)/2
	// ここに add 本の線を引いて最短距離を1にすると K = Kmax - add になる
	
	ll Kmax = (N-1)*(N-2)/2;
	if ( K > Kmax ){
		cout << "-1" << endl;
		return 0;
	}
	ll add = Kmax - K;
	cout << (N-1 + add) << endl;
	
	for ( int i = 1; i <= N; i++ ){
		for ( int j = i+1; j <= N; j++ ){
			if ( i == 1 )
				cout << i << " " << j << endl;
			else {
				if ( add > 0 ){
					add--;
					cout << i << " " << j << endl;
				}
				else
					return 0;
			}
		}
	}
	
	return 0;
}

