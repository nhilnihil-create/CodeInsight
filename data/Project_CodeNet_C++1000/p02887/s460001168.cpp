#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	string s;
	cin>>n>>s;
	
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]==s[i-1]) n--;
	}
	
	cout<<n;
	return 0;
}