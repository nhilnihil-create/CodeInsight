#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n,a,b,mn=0,sum=0;
	cin>>a>>b>>n;
	mn=min(b-1,n);
	sum=(long long int)((a*mn)/b)-a*(long long int)(mn/b);
	cout<<sum;
	return 0; 
} 
