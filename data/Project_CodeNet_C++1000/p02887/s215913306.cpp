#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;cin >> n;
	string s;cin>>s;
	
	auto res = unique(s.begin(), s.end());
	cout << string(s.begin(), res).length();
}