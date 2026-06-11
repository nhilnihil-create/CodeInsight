#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int p=0,q=0;
	for (int i = 0; i < 3; ++i)
	{
		if(s[i]=='R'){
			p=i;
			q=1;
			break;
	}
}
	if(p!=3){
		if (s[p+1]=='R')
		{
			q=2;
			if (s[p+2]=='R')
			{
				q=3;
			}
		}
	}

	cout<<q<<endl;
    return 0;
}