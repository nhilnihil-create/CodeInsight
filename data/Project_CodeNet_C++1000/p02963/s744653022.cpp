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
#define N 100010
//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
	ll s;
	scanf("%lld",&s);
	if(s==1000000000000000000)
    {
        printf("1000000000 0 0 1000000000 0 0\n");
        return 0;
    }
	ll d=1000000000LL,b=s/1000000000,c=1+b,a=s%1000000000;
	printf("0 %lld %lld 0 %lld %lld\n",a,b,c,d);
	return 0;
}
