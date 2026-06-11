#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int a=0,b=0;
		string ans = "YES";
		for(int i = 0 ; i < 10 ; i++){
			if( a > b ) swap(a,b);
			int x;
			cin >> x;
			if( x < a ){
				ans = "NO";
			}else if( b < x ){
				b = x;
			}else{
				a = x;
			}
		}
		cout << ans << endl;
	}
	
}