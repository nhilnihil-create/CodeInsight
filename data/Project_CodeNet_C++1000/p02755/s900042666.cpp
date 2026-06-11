/****************************
*  Developer : joshi08
*  Date  :  22-06-2020
*  Year  :  2020
****************************/

#include <bits/stdc++.h>

#define lli long long int
#define mod 1000000007
#define fi first
#define se second
#define ii pair<lli, lli>
#define mp make_pair
#define endl '\n'
const double PI = 3.141592653589793238460;
lli gcd(lli a, lli b) { if (a == 0) return b; return gcd(b % a, a);}
lli max(lli a, lli b) {if (a > b) return a; else return b;}
lli min(lli a, lli b) {if (a < b) return a; else return b;}
lli power(lli a,lli b) {lli i,p=1; for(i=0;i<b;i++){p*=a;} return p;}

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

	double a,b,k1,k2;
	
	lli i,p1,p2;
	
	cin>>a>>b;
	
	for(i=4;i<=1251;i++)
	{
		k1 = i*0.08;
		k2 = i*0.1;
		
		p1 = (int) k1;
		if(p1>k1)
			p1--;
			
		p2 = (int) k2;
		if(p2>k2)
			p2--;
		
		if(p1==a && p2==b)
		{
			break;
		}
	}
	if(i!=1252)
	{
		cout<<i;
	}
	else
	{
		cout<<-1;
	}
	

    return 0;
}

