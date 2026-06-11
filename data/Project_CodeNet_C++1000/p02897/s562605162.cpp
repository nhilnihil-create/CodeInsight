#include<bits/stdc++.h>
#define ll 	long long
#define pb push_back
using namespace std;

int main()
{

ll n,d=0;
cin>>n;
if(n%2==0)
{
 d=n/2;
}
else if(n%2)
d=(n/2)+1;

double f= d/(n*1.0);

printf("%0.10lf\n",f);
	return 0;
}