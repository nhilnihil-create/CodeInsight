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
    int n;
    cin >> n;
    vi c(n,0);
    rep(i,n-1){
        int a;
        cin >> a;
        a--;
        c[a]++;
    }
    rep(i,n)printf("%d%c", c[i], i==n-1?'\n':' ');
    return 0;
}