#include <bits/stdc++.h>
using namespace std;

int n;

string a[10] = {"", ".,!? ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n; ++i){
		string s;
		cin >> s;
		string t;
		for(int i=0; i<s.size(); ++i){
			char c = s[i];
			int j = i;
			while(c == s[i]) ++i;
			if(c != '0') t += a[c-'0'][(i-j-1)%(int)(a[c-'0'].size())];
			else --i;
		}
		cout << t << "\n";
	}
}
