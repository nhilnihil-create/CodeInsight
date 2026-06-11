// https://atcoder.jp/contests/abc158/tasks/abc158_b
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
#define lli long long int
#define numberofdigits(x) floor(log10(x)) + 1

int main()
{
    lli n,a,b,res;
    cin>>n>>a>>b;
    res = (n/(a+b))*a;
    n -= (n/(a+b))*(a+b);
    res += min(a,n);
    cout<<res<<"\n";
    return 0;
}