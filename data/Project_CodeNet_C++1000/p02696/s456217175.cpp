#include<bits/stdc++.h> 
using namespace std;
int main()
{
	long long int ans,x,a,b,n;
	cin>>a>>b>>n;
    if(n>=b)
    x=b-1;
    else
    x=n;
    int p=(a*x)/b;
    int q=a*(x/b);
    ans=p-q;
    cout<<ans;
	return 0;
}