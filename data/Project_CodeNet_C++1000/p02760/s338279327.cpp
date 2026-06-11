#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

v2 a(3, v1(3));
int n;

int main(){
	rep(i, 3){
		rep(j, 3){
			cin >> a[i][j];
		}
	}
	cin >> n;
	rep(i, n){
		int x;
		cin >> x;
		rep(i, 3){
			rep(j, 3){
				if(a[i][j] == x){
					a[i][j] = 0;
				}
			}
		}
	}
	rep(i, 3){
		if(a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0){
			cout << "Yes" << endl;
			return 0;
		}
	}
	rep(i, 3){
		if(a[0][i] == 0 && a[1][i] == 0 && a[2][i] == 0){
			cout << "Yes" << endl;
			return 0;
		}
	}
	if(a[1][1] == 0 && a[2][2] == 0 && a[0][0] == 0){
		cout << "Yes" << endl;
		return 0;
	}
	if(a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0){
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
}
