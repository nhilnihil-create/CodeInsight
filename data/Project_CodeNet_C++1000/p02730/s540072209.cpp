#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 1000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L

int main() {
	string s; cin >> s;
	int len, len2, len3;
	len = (s.length()-1)/2;
	for (int ii = 0; ii < len; ii++) {
		if (s[ii] != s[s.length()-1-ii]) goto NOT_KAI;
	}
	if (s.length()==3) goto KAI;
	len2 = (len - 1)/2;
	if (len2 == 0) {
		if ( s[0] != s[1] ) goto NOT_KAI;
	}
	for (int ii = 0; ii < len2; ii++) {
		if (s[ii] != s[len-1-ii]) goto NOT_KAI;
	}
	if (len2 == 0) {
		if(s[s.length()-1] != s[s.length()-2]) goto NOT_KAI;
	}
	for (int ii = len+1; ii < len+1+len2; ii++) {
		if (s[ii] != s[s.length()-1-ii]) goto NOT_KAI;
	}

KAI:
	cout << "Yes" << endl;
	return 0;

NOT_KAI:
	cout << "No" << endl;
	return 0;
}