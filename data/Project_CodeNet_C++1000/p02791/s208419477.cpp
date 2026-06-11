#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	int n;
	cin >> n;
	int m = 1e8;
	int c = 0;
	rep(i, n){
		int x;
		cin >> x;
		if(x <= m){
			c++;
			m = x;
		}
	}
	cout << c << endl;
}
