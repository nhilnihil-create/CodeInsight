#include<iostream>
#include<string>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; string s;
	cin >> n >> s;
	int ans = 1;
	for(int i=1; i<n; i++){
		if(s[i] != s[i-1]) ans++;
	}
	cout << ans;
	return 0;
}