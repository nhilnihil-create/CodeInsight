#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
	cin>>N;
	N<1000;
	N=N%10;
	if(N==2||N==4||N==5||N==7||N==9)
	{
	cout<<"hon";
	}
	else if(N==3)
	{
		cout<<"bon";
	}
	else
	{
		cout<<"pon";
	}
}