#include <iostream>
using namespace std;
int main(){
	int N, M, P;
	while( 1 ){
		cin >> N >> M >> P;
		if( N == 0 && M == 0 && P == 0 ) break;
		int money = 0, mn;
		for( int i = 1; i <= N; i++ ){
			int j;
			cin >> j;
			if(M == i) mn = j;
			money += j;
		}
		if( mn == 0 ){
			cout << 0 << endl;
		}else{
			money = money * (100 - P) / mn;
			cout << money << endl;
		}
	}
}