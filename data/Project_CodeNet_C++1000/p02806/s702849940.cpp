#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (int)(n); i++)
#define rep2(i,x,n) for(int i = (int)x; i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define repitr(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<string, int>> vp(n);
	rep(i, n) cin >> vp.at(i).first >> vp.at(i).second;
	string x;
	cin >> x;
	int ans = 0;
	bool flag = false;
	rep(i, n){
		if(flag == true) ans += vp.at(i).second;
		if(vp.at(i).first == x){
			flag = true;
		}
	}

	cout << ans << endl;

	return 0;
}