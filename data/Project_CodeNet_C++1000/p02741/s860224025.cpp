#ifdef __unix__
#include <bits/stdc++.h>
#else
#include <iostream>
#include <algorithm>
#include <math.h>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <bitset>
#endif

#define fastIO ios_base::sync_with_stdio(0), cin.tie(NULL)
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#define mkp make_pair
/*#define NUMTOSTR(x)  (unsigned char)((x) + 48);*/
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long  ull;
using namespace std;

int main() {
	fastIO;
	int ar[32] = { 1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51 };
	int k;
	cin >> k;
	cout << ar[k - 1];
	return 0;
}