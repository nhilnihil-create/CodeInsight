#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,i,j,cnt = 0;
	string s;
	cin >> n;
	cin >> s;
	sort(s.begin(),s.end());
	for(i=0;i<n;i+=2)
	{
		if(s[i]==s[i+1]) cnt++;
	}
	if(cnt == (n/2) && n%2==0) cout << "Yes\n";
	else cout << "No\n";
	
	return 0;
}