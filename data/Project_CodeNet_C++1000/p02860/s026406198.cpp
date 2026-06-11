#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	string st;
	cin >> st;
	if(n&1)
		cout << "No";
	else{
		string c1 = "" , c2 = "";
		for(ll i=0; i<st.length()/2; i++){
			c1 += st[i];
			c2 += st[st.length()/2 + i];
		}
		if(c1==c2)
			cout << "Yes";
		else
			cout << "No";
	}
	return 0;
}