#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
    string s,t;
    for(int i=0;i<a;i++)
    {
    	s += ( b+'0');
	}
	for(int i=0;i<b;i++)
    {
    	t += ( a+'0');
	}
	cout<<min(s,t)<<endl;
	
}