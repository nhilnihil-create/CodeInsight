#include <iostream>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int y,m,d,ans=0;
		cin >> y >> m >> d;
		while(y != 1000 || m != 1 || d != 1){
			d++;
			if( y % 3 ){
				if( d > 20 - (m+1) % 2 ) d = 1 , m++;
				if( m >= 11 ) m = 1 , y++;
			}else{
				if( d >= 21 ) d = 1 , m++;
				if( m >= 11 ) m = 1 , y++;
			}
			ans++;
		}
		cout << ans << endl;
	}
}