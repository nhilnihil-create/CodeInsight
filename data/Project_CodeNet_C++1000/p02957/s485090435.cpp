#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn =2e3+5;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a,b;
	cin>>a>>b;
	if((a+b)%2)
    {
        cout<<"IMPOSSIBLE"<<'\n';
    }
    else
    {
        cout<<(a+b)/2<<'\n';
    }



}
