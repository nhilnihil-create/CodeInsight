#include<bits/stdc++.h>

#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ll long long int
 
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int temp=(n+1)/2;
	cout<<fixed<<setprecision(10)<<temp/(double)n;
	return 0;
}