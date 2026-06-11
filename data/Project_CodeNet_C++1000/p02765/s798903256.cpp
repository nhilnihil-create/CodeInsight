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
int main(){
	int inner;
	int n;
	int k;
	cin >> n >> k;
	if (n > 10) {
		cout << k;
		return 0;
	}
	else inner = k + 100 * (10 - n);
	cout << inner;
	return 0;
}
