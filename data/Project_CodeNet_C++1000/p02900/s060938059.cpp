#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <ctime>
#define ll long long
using namespace std;

ll solve(ll x)
{
    ll cnt=1;
    for(ll i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            cnt++;
            while(x%i==0)
            {
                x/=i;
            }
        }
    }
    if(x>1)
        cnt++;
    return cnt;
}

ll gcd(ll a,ll b)
{
    while(b)
    {
        ll t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main(){
    ll a,b;
    scanf("%lld%lld",&a,&b)==2;
    ll x=gcd(a,b);
    printf("%lld\n",solve(x));
	return 0;
}
