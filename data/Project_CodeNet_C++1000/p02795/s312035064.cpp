#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define gap ' '
#define L(i) ((i) - (&i))

const int MAXN = 2*1e5+10;
const int MAX = 100;
const int MOD = 1e9+7;
const int INF = 1e9 + 5;
int main(){
	int h,w,n; cin >> h >> w >> n;
	if(h > w){	
		int ans = 0, b = 0;
		while(b < n){
			b+=h;
			ans++;
		}
		cout << ans << endl;
	}
	else{
		int ans = 0, b = 0;
		while(b < n){
			b+=w;
			ans++;
		}
		cout << ans << "\n";
	}
 	return 0;
}