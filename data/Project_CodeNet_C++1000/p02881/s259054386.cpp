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
#define inf 0x3f3f3f3f
#define N 4000010
//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
ll a[N];

int main(){
	ll n,cnt=0;
	scanf("%lld",&n);
	ll len=sqrt(n);
	for(ll i=1;i<=len;i++)
    {
        if(n%i==0)
            a[++cnt]=i;
    }
    printf("%lld\n",a[cnt]+n/a[cnt]-2);
	return 0;
}
