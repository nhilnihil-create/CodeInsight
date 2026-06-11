#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;
const int IINF = INT_MAX;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000000000
int main(){
    ll w,h,x,y;
	cin >> w >> h >> x >> y;
	
	double w1 = w;
	double h1 = h;
	cout << fixed << setprecision(9) <<  (w1*h1)/2 << " ";
	
	if(2*y == h && 2*x == w){
		 cout << 1 << endl;
	}else{
		 cout << 0 << endl;
	}
    return 0;	
}