#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> ac(n),wa(n);
	rep(i,m){
		int p;
		string s;
		cin >> p >> s;
		p--;
		if(ac[p]) continue;
		if(s == "AC") ac[p] = 1;
		else{
			wa[p]++;
		}
	}
	int acwa =0;
	int wawa = 0;
	rep(i,n){
		if(ac[i] == 1) acwa++;
		if(ac[i]) wawa += wa[i];
	}
	cout << acwa << " " << wawa << endl;
}