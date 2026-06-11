#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	for(int i = 0;i<n;i++)
	{
		string a;
		cin >> a;
		sort(a.begin(),a.end());
		s.at(i)=a;
	}
	sort(s.begin(),s.end());
	long long cnt = 0,b=0;
	for(int i=0;i<n-1;i++)
	{
		if(s.at(i)==s.at(i+1))
		{
			b++;
		}
		else
		{
			cnt+=(b*(b+1))/2;
			b=0;
		}
	}
	cnt+=(b*(b+1))/2;
    cout << cnt << endl;
}
