#include <bits/stdc++.h>
using namespace std;
int main(){
	int m, d, ans; ans = 0;  
	cin >> m >> d; 
	for(int i=22; i<=d; ++i){
		int d1 = i%10; 
		int d2 = i/10; 
		if(d1 >= 2 && d2 >= 2){
			int mm = d1*d2; 
			if(mm <= m) ++ans; 
		}
	}
	cout << ans << endl; 
	return 0; 
}