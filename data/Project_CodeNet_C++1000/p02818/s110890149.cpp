#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define loop(i,s,e) for(ll i=s;i<e;i++)
#define test ll x;cin>>x;while(x--)
#define pb push_back
#define vec vector<ll>
#define sortvec(x) sort(x.begin(),x.end())
#define sz(x) x.size()

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a,b,k;
    cin>>a>>b>>k;
    if (k>=a+b)
    	cout<<"0 0\n";
    else
    {
    	if (k>=a)
    	{
    		k-=a;
    		a=0;
    		b-=k;
    		cout<<a<<" "<<b<<"\n";
    	}
    	else
    	{
    		a-=k;
    		cout<<a<<" "<<b<<"\n";
    	}
    }
}
