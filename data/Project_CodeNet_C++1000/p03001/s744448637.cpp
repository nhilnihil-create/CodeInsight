#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	double W, H, x, y;
	cin >> W >> H >> x >> y;
	if(W/2 - 0.0001 < x && x < W/2 + 0.0001 && H/2 - 0.0001 < y && y < H/2 + 0.0001) {
		printf("%.10f", W * H /2);
		cout << " " << 1 << endl;
	} else {
		printf("%.10f", W * H /2);
		cout << " " << 0 << endl;
	}

}
