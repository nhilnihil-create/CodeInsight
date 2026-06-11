#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
	int n;
	cin >> n;
	set<string> st;
	string s;
	
	for(int i = 0; i<n; i++)
	{
		cin >> s;
		st.insert(s);
	}
	cout << st.size() << "\n";
	
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
