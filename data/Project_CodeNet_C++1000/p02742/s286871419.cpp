#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long 
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=0;
    ll m=0;
    cin>>n>>m;
    if(n==1||m==1)
    {
    	cout<<1<<"\n";
    	return 0;
    }
    if((n*m)%2==0)
    {
    	cout<<(n*m)/2<<"\n";
    }
    else
    {
    	cout<<((n*m)/2)+1<<"\n";
    }


    return 0;
}
