#include "bits/stdc++.h"
using namespace std;

//24
typedef long long ll;

int main() {
	double h, w, x , y;
	cin >> h >> w >> x >> y;
	if (x == h / 2.0 && y == w / 2.0) {
		cout << fixed << setprecision(12) << (double) (h * w) / 2 << " " << 1; 
	}else {
		double ans = (double) (h * w) / 2.0;
		cout << fixed << setprecision(12) << ans << " " <<  0;
	}
	//((1 + 2)  * x)/ 2  
}

//3,0        2,3
     //.      2,2
    
//0,1
//0,0        0,2
