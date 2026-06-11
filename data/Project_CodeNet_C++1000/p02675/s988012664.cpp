#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;

int main(){
	ll T = 1;
	//cin >> T;
	while (T--){
     int n;
     cin >> n;
     int x = n % 10;
     if (x == 2 || x == 4 || x == 5 || x == 7 || x == 9) {
		 cout << "hon" << endl;
	 } else if (x == 0 || x == 1 || x == 6 || x == 8) { 
		 cout << "pon" << endl;
	 } else if (x == 3) { 
		 cout << "bon" << endl;
	 }
	 
	}
}
	

