#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using ll = long long;

int main()
{
    int n,m;
    cin >> n >> m;
    int sum = 0;
    rep(i,m) {
        int a;
        cin >>a;
        sum += a;
    }
    if( n >= sum) cout << (n - sum) << endl;
    else cout << "-1" << endl;
    return 0;
}