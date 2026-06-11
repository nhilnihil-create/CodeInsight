#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n-1);
	int happy = 0;
	rep(i, n) cin >> a.at(i);
	rep(i, n){
		cin >> b.at(i);
		happy += b.at(i);
	}
	rep(i, n-1) cin >> c.at(i);

	rep(i, n-1){
		if(a.at(i)+1 == a.at(i+1)) happy += c.at(a.at(i)-1);
	}

	cout << happy << endl;
	return 0;
}