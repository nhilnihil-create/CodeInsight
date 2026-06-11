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
	ll a;
	cin >> a;
	bool ns = false;
	for(ll i=1; i<=9; i++)
		for(ll j=1; j<=9; j++)
			if(i*j == a)
				ns = 1;
	if(ns)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}