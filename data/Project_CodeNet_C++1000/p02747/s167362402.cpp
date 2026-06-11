#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	string s;
	cin>>s;
	if(s.length()%2)cout<<"No"<<endl;
	else
	{
		for(int i=0;i<s.length()-1;i+=2)
		{
			if(s.substr(i,2)!="hi")
			{
				cout<<"No"<<endl;
				return 0;
			}
		}
		cout<<"Yes"<<endl;
	}
	return 0;
}