#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#define endl "\n"
typedef long long int ll;
typedef unsigned long long int ull;
typedef float fl;
typedef long double ld;
using namespace std;

int GCD(int a,int b)
{
    if (b==0) return a; else return GCD(b,a%b);
}

void solve()
{   int k; cin >> k; ll sum=0;
    for (int a=1;a<=k;++a) {
        for (int b=1;b<=k;++b) {
            for(int c=1;c<=k;++c) {
                sum+=GCD(GCD(a,b),c);
    }}}
            cout << sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
