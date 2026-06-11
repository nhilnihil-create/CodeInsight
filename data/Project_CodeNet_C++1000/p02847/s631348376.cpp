#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> s = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

int main()
{
	reverse(s.begin(),s.end());
	string t;
	cin >> t;
	for(int i = 0;i<7;i++)
	{
		if(s[i]==t)
		{
			cout<<i+1<<endl;
		}
	}
}