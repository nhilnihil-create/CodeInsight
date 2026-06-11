#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iomanip>
#include<sstream>
#include<map>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 1;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll MOD =  1000000007;
const ll INF =  1LL << 60;
ll n, m, x = 0, y,z,w,h, sum= 0, ans = 0;
int main(void) {
    cin >> n >> m;
    if (n > 9 || m > 9) {
        cout << -1 << endl;
    }
    else {
        cout << n * m << endl;
    }
}