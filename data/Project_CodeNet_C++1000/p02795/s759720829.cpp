#include <iostream>
#include <iomanip>
#include <algorithm>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    int h,w,n;
    cin >> h >> w >> n;
    int M = max(h,w);
    cout << (n+M-1)/M << endl;
    return 0;
}