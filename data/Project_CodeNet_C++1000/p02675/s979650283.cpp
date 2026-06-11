#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	string s=to_string(n);
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='2' || s[i]=='4' || s[i]=='7' || s[i]=='9'|| s[i]=='5')
		{
			cout<<"hon"<<endl;
			break;
		}
		else if(s[i]=='3')
		{
			cout<<"bon"<<endl;
			break;
		}
		else if(s[i]=='0' || s[i]=='1' || s[i]=='6' || s[i]=='8')
		{
			cout<<"pon"<<endl;
			break;
		}
	
	}

	
}