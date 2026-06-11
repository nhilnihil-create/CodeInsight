#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <functional>
#include <map>
#include <math.h>
#include <list>

using namespace std;
#define ll long long int


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	queue<ll> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);
	q.push(9);
	int k; cin >> k;
	ll i = 0;


	while (k--) {
		i = q.front();
		q.pop();
		if (i % 10 != 0) q.push(i * 10 + (i % 10) - 1);
		q.push(i * 10 + (i % 10));
		if(i% 10 != 9) q.push(i * 10 + (i % 10) + 1);
	}

	cout << i << endl;

	return 0;
}