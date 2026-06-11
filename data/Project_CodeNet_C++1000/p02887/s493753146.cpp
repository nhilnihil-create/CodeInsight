#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,ans;
	string s;
	cin >> n >> s;
	ans = n;
	for(int i=1;i<n;i++)
	{
		if(s.at(i-1)==s.at(i))
		{
			ans--;
		}
	}
	cout << ans << endl;
}
