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
	string st;
	cin >> n >> st;
	stack<char> stc;
	for(ll i=0; st[i]; i++){
		if(stc.empty())
			stc.push(st[i]);
		else if(stc.top() != st[i])
			stc.push(st[i]);
	}
	cout << stc.size();
	return 0;
}