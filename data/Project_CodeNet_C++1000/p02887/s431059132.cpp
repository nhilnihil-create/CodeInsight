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
	int n;
	string s;
	cin >> n >> s;
	int cnt = 1;
	rep(i, n-1){
		if (s[i] != s[i +1]) {
			cnt++;
		}
	}
	cout << cnt;
}