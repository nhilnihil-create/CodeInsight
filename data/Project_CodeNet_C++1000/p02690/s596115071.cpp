#include<bits/stdc++.h>
using namespace std;
bool check(int x)
{
	int a,b;
	for(a=-1000;a<=1000;a++)
	{
    for(b=-1000;b<=1000;b++)
    {
    long long int c=pow(a,5);
    long long int d=pow(b,5);
    if(c-d==x)
    {
    cout<<a<<" "<<b;
    return 1;
    }
	}
    }
	return 0;
}
int main()
{
	long long int x;
	cin>>x;
	int f=check(x);
    return 0;
}