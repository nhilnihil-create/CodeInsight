#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for(int i=0;i<n;i++)
	{
		cin >> h.at(i);
	}
	string ans="Yes";
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			h.at(i)-=1;
		}
		else
		{
			if(h.at(i)<h.at(i-1))
			{
				ans="No";
				break;
			}
			else if(h.at(i)>h.at(i-1))
			{
				h.at(i)-=1;
			}
		}
	}
	cout << ans << endl;
}
