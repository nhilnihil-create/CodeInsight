#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n+1),b(n);
	long long sm=0;
	for(int i=0;i<n+1;i++)
	{
		cin >> a.at(i);
	}
	for(int i=0;i<n;i++)
	{
		cin >> b.at(i);
		if(a.at(i)>=b.at(i))
		{
			sm+=b.at(i);
		}
		else
		{
			sm+=a.at(i);
			b.at(i)-=a.at(i);
			if(a.at(i+1)>=b.at(i))
			{
				a.at(i+1)-=b.at(i);
				sm+=b.at(i);
			}
			else
			{
				sm+=a.at(i+1);
				a.at(i+1)=0;
			}
		}
	}
	cout << sm << endl;
	return 0;
}
