#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 100005
 
#define PI   3.14159265358979323846264338327950

#define PB push_back 
#define F first
#define S second
 
#define ll 	 long long int

#define mod  1000000007


map<char, int> m;


int main()
{
	FAST;
	string s;
	cin >> s;
	for(ll i = 0; i < s.size(); i ++){
		m[s[i]] = 1;
	}
	ll x = 0;
	for(char i = 'A' ;i <= 'Z'; i++){
		x += m[i];
	}
	if(x == 2){
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}