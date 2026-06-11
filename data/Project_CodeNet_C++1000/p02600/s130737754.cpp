#include <bits/stdc++.h>
#include <stdio.h>
typedef long long int LL;
#define fr(i,p,n) for(LL i=p;i<n;i++)
#define fr1(i,p,n) for(LL i=p;i>=n;i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define precise cout << std::setprecision(10) << std::fixed;

using namespace std;
 
int main()
{
    int x;
	cin>>x;
	int rating;
	
	if(x>=400 && x<=599)
	  rating=8;
	else if(x>=600 && x<=799)
	  rating=7;
	else if(x>=800 && x<=999)
	  rating=6;
	else if(x>=1000 && x<=1199)
	  rating=5;
	else if(x>=1200 && x<=1399)
	  rating=4;
	else if(x>=1400 && x<=1599)
	  rating=3;
	else if(x>=1600 && x<=1799)
	  rating=2;
	else
	  rating=1;  
	 
	cout<<rating<<endl;  
    return 0;
}