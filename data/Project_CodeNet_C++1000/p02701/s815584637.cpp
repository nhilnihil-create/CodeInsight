#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n;
	string s;
	set<string>x;
	cin >> n;
	while(n--){
		cin >> s;
		x.insert(s);
	}
	cout << x.size() << endl;
}