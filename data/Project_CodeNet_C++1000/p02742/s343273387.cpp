#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	ll h,w;
	cin >> h >> w;
	if(h==1 || w==1) cout << 1 << endl;
	else if(h*w%2==0) cout << h*w/2 << endl;
	else cout << (h*w+1)/2 << endl;
	return 0;
}
