#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define pb push_back
#define mp make_pair
#define f first
#define s second
int main()
{
	ll n,x,t,val;
	cin>>n>>x>>t;
    val=n/x;
    if (n%x)
    {
    	val++;
    }
    cout<<val*t<<endl;
	return 0;
}
