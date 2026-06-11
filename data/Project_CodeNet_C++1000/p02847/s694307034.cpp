#include <bits/stdc++.h>
using namespace std;
int main()
{
  	string s[10];
	
	s[1]="SAT";
	s[2]="FRI";
	s[3]="THU";
	s[4]="WED";
	s[5]="TUE";
	s[6]="MON";
	s[7]="SUN";
	
	string value;
	cin>>value;
	for(int i=1;i<8;i++)
	{
		if(value == s[i])
		{
			cout<<i;
			break;
		}
	}
	
}