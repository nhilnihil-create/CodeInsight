#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main()
{
    double n;
    cin >> n;
    ll lb = 0, ub = INF;
    while(ub - lb > 1){
        ll mid = (lb + ub)/2;
        if(int(mid*1.08) <= n) lb = mid;
        else ub = mid;
    }
    if(int(double(lb*1.08)) != n) cout << ":(" << endl;
    else cout << lb << endl;
    return 0;
}
