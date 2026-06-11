#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int N;
	cin >> N;
	string s = "";
	for(int i=0;i<N;i++)
	{
		int x,y;
		cin >> x >> y;
		if(x==y)
			s += "1";
		else
			s += "0";
	}
	for(int i=1; i<N-1;i++)
	{
		if(s[i]-'0' && s[i-1]-'0' && s[i+1]-'0')
		{
			cout << "Yes";
			return;
		}
	}
	cout<<"No";
}


int main() {
    int t;
    // cin>>t;
	// while(t--)
		solve();
	return 0;

}