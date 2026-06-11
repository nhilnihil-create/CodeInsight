#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
int main()
{
	int n;cin>>n;
	string s;cin>>s;
	int t=0;
	for(int i=0;i<n;)
	{
		if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C')
		{
			t++;
			i+=3;
		}
		else i++;
	}
	printf("%d\n",t);
}