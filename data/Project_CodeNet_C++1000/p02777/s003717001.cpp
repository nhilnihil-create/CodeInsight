#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
ll Max = 10 + 1e12;
int N = 5 + 1e5;


int main()
{
	string s, t;
	int a, b;
	cin >> s >> t >> a >> b;
	string u; cin >> u;
	if (u == s) a--;
	if (u == t) b--;
	cout << a <<" "<< b;
}