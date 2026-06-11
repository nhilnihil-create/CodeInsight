#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
#define MAXX 200010
 
#define PI   3.14159265358979323846264338327950
 
#define PB push_back 
#define F first
#define S second
 
#define ll 	long long 
 
#define mod  1000000007
 

 
int main()
{
	FAST;
	string s;
	cin >> s;
	
	bool f = true;
	for(int i = 0; i < s.size(); i +=2){
		if(s[i] != 'h' || s[i+1] != 'i'){
			f = false;
		}
	}
	if(f){
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}