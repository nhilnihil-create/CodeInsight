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
	ll count = 0;
	for (int i = 0; i < 1000; i++)
	{
		string val = to_string(i);
		if (val.length() == 1)
		{
			string res = "00";
			res += val;
			val = res;
			//cout << val << endl;
		}
		else if (val.length() == 2)
		{
			string res = "0";
			res += val;
			val = res;
			//cout << val << endl;
		}
		ll k = 0;
		for (int j = 0; j < n; j++)
		{
			if (val[k] == s[j])
			{
				k++;
				if (k == 3)
				{
					//cout << val << endl;
					count++;
					break;
				}
			}
		}
	}
	cout << count << endl;
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