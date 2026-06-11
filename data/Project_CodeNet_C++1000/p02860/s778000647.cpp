#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,i,cnt,cnt1=0;
	string s;
	char ch;
	cin>>n>>s;
	if(n==1)
	cout<<"No"<<endl;
	else
	{
		for(ch='a';ch<='z';ch++)
	    {
		    cnt=0;
	    	for(i=0;s[i]!='\0';i++)
	    	{
    			if(s[i]==ch)
	    		cnt++;
    		}
	    	if(cnt%2!=0)
	    	{
		    	cnt1++;
		    	break;
		    }
    	}
    	if(cnt1==1)
    	cout<<"No"<<endl;
    	else
    	cout<<"Yes"<<endl;
    }
    return 0;
}