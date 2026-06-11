/*
Created on Mon Aug 31 14:20:02 2020

@author: roastedcoder

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
const int mod = 1e9+7;
const int INF = INT_MAX;
#define endl "\n"
#define append push_back
#define roastedcoder ios_base::sync_with_stdio(false); cin.tie(NULL);
//__________________________________________________________________


int main() {
	roastedcoder
	string s; cin>>s;
	if(s[1] == 'R') {
		if(s[0] == 'R' && s[2] == 'R') cout<<3;
		else if(s[0] == 'R' || s[2] == 'R') cout<<2;
		else cout<<1;
	}
	else if(s[0] == 'R' || s[2] == 'R') cout<<1;
	else cout<<0;
}

//__________________________________________________________________
/*
Sample Input:
RRS


Sample Output:
2

*/