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
#define N 1000000000
using namespace std;

int main(){
    ll s;
    scanf("%lld",&s);
    if(s==1000000000000000000)
    {
        printf("0 0 1000000000 0 0 1000000000\n");
        return 0;
    }
    ll a=s/N+1,d=N;
    ll b=a*d-s,c=1LL;
    printf("0 0 %lld %lld %lld %lld\n",a,b,c,d);
	return 0;
}
