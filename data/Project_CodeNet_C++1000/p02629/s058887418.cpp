#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	ll n;
	cin >> n;

	vector<int> a;

	while(n > 0)
	{
		if(n%26 == 0)
		{
			a.push_back(26);
			n--;
		}
		else
			a.push_back(n % 26);

		n /= 26;
	}

	for(int i = a.size()-1; i >= 0; i--)
		cout << char(a[i]+'a'-1);

	return 0;
}