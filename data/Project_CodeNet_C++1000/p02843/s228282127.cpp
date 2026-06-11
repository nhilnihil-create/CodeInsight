#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;

const int mod = 1e9+7;
const int INF = 2000000;
const double PI = acos(-1.0);

int main() {
    
	int x;
	cin >> x;
	for(int i=1;i<=x;++i){
		if(100*i > x) break;
		if(100*i <= x && x <= 100*i+5*i) {
			puts("1");
			return 0;
		}
		
	}
	puts("0");
}
