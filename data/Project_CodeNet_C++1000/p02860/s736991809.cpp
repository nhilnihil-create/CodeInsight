#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul  unsigned long long int
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod
//ll divide(ll a, ll b)  //euler's theorem(a/b)%mod
//{
//   return a*power(b,mod-2)%mod;  //only when mod is prime
//}

ll power(ll x, ll y)
{
    ll res = 1;
   while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}
int main()
{
    speed;
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n&1)
    cout<<"No\n";
    else
    {
    	if(s.substr(0,n/2)==s.substr(n/2))
    	cout<<"Yes\n";
    	else
    	cout<<"No\n";
	}


	return 0;
}
