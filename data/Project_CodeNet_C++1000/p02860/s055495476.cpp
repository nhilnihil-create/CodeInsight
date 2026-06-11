#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define debug1(a) cout<<#a<<" "<<(a)<<endl;
#define debug2(a,b) cout<<#a<<" "<<(a)<<" "<<#b<<" "<<(b)<<endl;
#define debug3(a,b,c) cout<<#a<<" "<<(a)<<" "<<#b<<" "<<(b)<<" "#c<<" "<<(c)<<endl;
typedef long double ld;
void solve()
{
	ll n;
	cin >> n;
	string s;
	cin >> s;
	if (n % 2 == 0)
	{
		string s1;
		string s2;
		for (int i = 0; i < (n / 2); i++)
		{
			s1 += s[i];
		}
		for (int i = (n / 2); i < n; i++)
		{
			s2 += s[i];
		}
		//cout << s1 << " " << s2 << endl;
		if (s1 == s2)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	else
	{
		cout << "No" << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}
}