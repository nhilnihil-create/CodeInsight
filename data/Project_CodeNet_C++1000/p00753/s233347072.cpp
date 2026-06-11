#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;

int main() 
{
    ll s[1000000] = {}; //素数なら0
    s[0] = 1;
    s[1] = 1;
    for(ll i=2;i*i<1000000;i++)
    {
        if(s[i]==0){
            for(ll j=i*i ; j<1000000 ; j+=i ){   s[j]=1; }
        }
	}
	
	int n;
	while(cin >> n && n!=0)
	{
		ll ans =0;
		for(ll i=n+1;i<=2*n;i++)
		{
			if(s[i]==0){ans++;}
		}
		
		cout << ans << endl;
		
	}
	return 0;
}