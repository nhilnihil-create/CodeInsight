#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
using namespace std;
const long long N = 1e10 + 7;
const int maxn = 2e5 + 5;
const long long INF = 8e18;
typedef long long ll;
#define for0(i,n) for(int i = 0;i < n;i++)
#define for1(i,n) for(int i = 1;i <= n;i++)


int main()
{
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    while(n && a >= b){
        b *= 2;
        n--;
    }
    while(n && b >= c){
        c *= 2;
        n--;
    }
    if(b > a && c > b)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
