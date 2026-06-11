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
using ll = unsigned long long;


int main() {

	string s;
	cin >> s;
	char S[4] = { s[0],s[1],s[2],s[3] };

	sort(s.begin(), s.end());
	bool ans = false;
	if (s[0] == s[1] && s[2] == s[3]&&s[0]!=s[2]) ans = true;
	puts(ans ? "Yes" : "No");
	return 0;
}