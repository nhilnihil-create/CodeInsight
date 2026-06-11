#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int n;
	cin >> n >> s;
	int cnt = 0;
	for(int i = 0; i+2 < n;i++){
			string abc = s.substr(i,3);
			if(abc=="ABC"){
				cnt++;
			}
	}
	cout << cnt;
	return 0;
}
