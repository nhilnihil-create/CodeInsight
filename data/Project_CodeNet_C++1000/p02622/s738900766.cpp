#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll cnt=0;
	string s,t;
	cin >> s >> t;
	for(int i=0; i<s.size(); i++)if(s[i]!=t[i])cnt++;
	cout << cnt << endl;
}