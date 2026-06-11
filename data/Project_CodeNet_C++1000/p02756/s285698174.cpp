#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    string s;
    cin>>s;
    deque<char>arr;
	for(int i=0; i<s.size(); i++)
	{
		arr.push_back(s[i]);
	}
	int sit=1;
	int q;
	cin>>q;
	while(q--)
	{
		int num1,num2;
		char ch;
		cin>>num1;
		if(num1==1)
		{
			sit=sit*(-1);
		}
		else
		{
			cin>>num2>>ch;
			if(sit==1)
			{
				if(num2==1)
				 arr.push_front(ch);
				else
				 arr.push_back(ch);
			}
			else
			{
				if(num2==1)
				 arr.push_back(ch);
				else
				 arr.push_front(ch);
			}
		}
	}
	if(sit==1)
	{
		while(!arr.empty())
		{
			char ch=arr.front();
			cout<<ch;
			arr.pop_front();
		}
	}
	else
	{
		while(!arr.empty())
		{
			char ch=arr.back();
			cout<<ch;
			arr.pop_back();
		}
	}
	return 0;   
}