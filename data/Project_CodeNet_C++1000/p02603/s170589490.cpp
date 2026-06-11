#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	ll money = 1000;
	rep(i,n-1){
		ll stock = 0;
		if(a[i+1] > a[i]){
			stock = money / a[i];
			money -= stock * a[i];
			money += stock * a[i+1];
		}
	}
	cout << money << endl;
    return 0;
}
