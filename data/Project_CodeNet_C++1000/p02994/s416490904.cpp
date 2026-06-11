#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,l;
	cin >> n >> l;
	int ans = 0;
	int nokori = 0;
	int mn = 100000000;
	int a = 0;
	for(int i = 1; i <=n; i++){
		ans += l+i-1;
	}
	for(int i = 1; i <=n; i++){
		nokori = ans;
		nokori += -l-i+1;
		if(abs(ans-nokori) < mn){
			mn = abs(ans - nokori);
			a = nokori;
		}
	}
	cout << a << endl;
}

// cout << fixed << setprecision(15) <<  << endl;