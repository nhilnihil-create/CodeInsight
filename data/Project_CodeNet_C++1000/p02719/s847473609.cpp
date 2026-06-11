#include<bits/stdc++.h>
using namespace std;
# define ld long double
#define lli long long int
int main()
{

lli n,k;
cin>>n>>k;

lli x=ceil((ld)n/(ld)k);
lli y=x-1;

lli ans=min(abs(n-x*k),abs(n-y*k));

cout<<ans;




	return 0;
}