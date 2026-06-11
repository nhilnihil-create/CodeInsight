#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;

int main(){
	ll T = 1;
	//cin >> T;
	while (T--){
	 int a; int b; int c; int d; int e; int x = 0;
	 cin >> a >> b >> c >> d >> e;
	 if (a == 0) {
		 x = 1;
	 }
	 if (b == 0) {
		 x = 2;
	 }
	 if (c == 0) {
		 x = 3;
	 }
	 if (d == 0) {
		 x = 4;
	 }
	 if (e == 0) {
		 x = 5;
	 }
	 cout << x << endl;
	}
}
	
