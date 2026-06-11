#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	int n, m;
	cin >> n >> m;
	v1 a(n+1, 0);
	v1 b(n+1, 0);
	rep(i, m){
		int p;
		string s;
		cin >> p >> s;
		if(s == "AC"){
			a[p]++;
		}else if(s == "WA" && a[p] == 0){
			b[p]++;
		}
	}
	int ac = 0;
	int wa = 0;
	rep(i, n){
		if(a[i+1] != 0){
			ac++;
			wa += b[i+1];
		}
	}
	cout << ac << " " << wa << endl;
}
