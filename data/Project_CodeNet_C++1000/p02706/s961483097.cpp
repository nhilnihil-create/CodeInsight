#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using P  = pair<int,int>;
const int INF = 1001001001;
const int MOD = 1000000007;



int main(){
    int n, m;
    cin >> n >> m;
    rep(i,m){
        int a;
        cin >> a;
        n -= a;
    }
    if(n<0)
        cout << -1 << endl;
    else
        cout << n << endl;
    return 0;
}