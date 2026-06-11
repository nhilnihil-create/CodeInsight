#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;


int main() {
	int	k;
	cin >> k;
	int a[1000001] = {};
	a[1] = 7 % k;
	for(int i = 2;i<=k;i++){
		a[i] = (a[i - 1]*10 + 7) % k;
	}
	for(int i = 1; i <= k;i++){
		if(a[i] == 0){
			cout << i <<endl;
			return (0);
		}
	}
	cout << "-1" << endl;
}