#include <cstdio>
#include <utility>
#include <typeinfo>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <tuple>
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int ll;
using namespace std;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;

int main()
{

    double pi=3.141592653589;
    double x;
    cin>>x;
    
    printf("%f %f\n",x*x*pi,2*x*pi);
    
    return 0;
}