  
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

// https://leetcode.com/problems/count-complete-tree-nodes/
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	int m = min(a+b, a+c);
	m = min(m, b+c);
	cout << m;

    return 0;
}