#include <string>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		set<string> ans;
		string temp;
		cin>>temp;
		for(int j=1;j<temp.size();j++)
		{
			string a=temp.substr(0,j);
			string b=temp.substr(j,temp.size());
			ans.insert(a+b);
			ans.insert(b+a);
			reverse(a.begin(),a.end());
			ans.insert(a+b);
			ans.insert(b+a);
			reverse(a.begin(),a.end());
			reverse(b.begin(),b.end());
			ans.insert(a+b);
			ans.insert(b+a);
			reverse(a.begin(),a.end());
			ans.insert(a+b);
			ans.insert(b+a);
		}
		cout<<ans.size()<<endl;
	}
}