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
	int n;
	cin >> n;
	vector<int> a(n),b(n),c(n-1);
	rep(i,n){
		int x;
		cin >> x;
		x--;
		a[i] = x;
	}
	rep(i,n){
		cin >> b[i];
	}
	rep(i,n-1){
		cin >> c[i];
	}
	int sum = 0;
	int pre = -2;
	rep(i,n){
		sum += b[a[i]];
		if(pre+1 == a[i]){
			sum += c[pre];
		}
		pre = a[i];
	}
	cout << sum << endl;
	return 0;
}