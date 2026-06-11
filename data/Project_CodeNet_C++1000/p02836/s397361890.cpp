#include <bits/stdc++.h>
#define ll long long
//push_back make_pair emplace vector double float _unordered_map unodered_set queue stack sort begin end clear
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main() { fastIO
	int l, r;l = 0; 
	string str;
	cin >> str;
	r = str.size() - 1;int ans = 0;
	if (str.size()%2 == 0){
		while (r - l >= 1){
			if (str[l] != str[r])++ans;
			++l;--r;
		}
	}
	else while (r != l){
		if (str[l]!=str[r])++ans;
		++l;--r;
	}
	cout << ans << endl;
}
