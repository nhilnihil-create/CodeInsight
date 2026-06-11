#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> ar(n, vector<int>(32));
	rep(i, n){
		cin >> a[i];
		rep(j, 32){
			ar[i][j] = a[i]%2;
			a[i] /= 2;
//			cout << ar[i][j] << ' ';
		}
//		cout << endl;
	}
	rep(j, 32){
		int cou = 0;
		rep(i, n){
			cou += ar[i][j];
		}
		if(cou%2 == 1){
			rep(i, n){
				ar[i][j]--;
				ar[i][j] *= -1;
			}
		}
	}
	rep(i, n){
		int ans = 0;
		rep(j, 32){
			ans += ar[i][j] * pow(2,j);
		}
		cout << ans << ' ';
	}
	cout << endl;
	return 0;
}