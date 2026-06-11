#include <bits/stdc++.h>
#define ll long long
#define omar main
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//push_back make_pair emplace vector double float _unordered_map unodered_set queue stack sort begin end clear second first
using namespace std;

int omar() { fastIO
	int n; string str;
	cin >> n >> str;
	if (n%2) cout << "No" << endl;
	else {
		int l = 0, r = (n / 2);
		bool answer = 1;
		while (r != n){
			if (str[l] != str[r])answer = 0;
			if (!answer)break;
			++l;++r;
		} cout << ((answer)? "Yes" : "No") << endl;
	}
}
