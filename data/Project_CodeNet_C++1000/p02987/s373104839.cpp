#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep2(i,n) for(int i = -1; i < (n); i++)
#define PI 3.141592653589793

using namespace std;
using ll = long long;

const ll MA = 1000005;
int cnt[2];
int c[2];
int main() {

	string s;
	cin >> s;
	
	sort(s.begin(), s.end());

	if (s[0] == s[1] && s[2] == s[3]&&s[1]!=s[2]) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;



	return 0;
}