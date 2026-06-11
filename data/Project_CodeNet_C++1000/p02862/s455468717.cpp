#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<long long, long long>;
const long long INF = 1001001001;
const long long MOD = 1000000007;
const double EPS = 1e-10;
struct Edge { int from, to; long long cost; };
using Graph = vector<vector<Edge>>;

template<typename T = long long>
T mod_pow(T a, T x, T md) {
    T res = 1;
    while(x) {
        if(x & 1) res = res * a % md;
        a = a * a % md;
        x >>= 1;
    }
    return res;
}

long long inv_com(int n, int r, long long md) {
    if(n - r < r) r = n - r;
    long long x = 1, y = 1;
    for(int i = 2; i <= r; i++) x = (x * i) % md;
    for(int i = n - r + 1; i <= n; i++) y = (y * i) % md;
    return y * mod_pow(x, md - 2, md) % md;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x,y;
    cin>>x>>y;
    if((x+y)%3){
        cout<<0<<endl;
        return 0;
    }
    int z=0;
    for(;;z++){
        int tx=x-z;
        int ty=y-2*z;
        if(tx<0||ty<0){
            cout<<0<<endl;
            return 0;
        }
        if(tx==ty*2)break;
    }
    cout<<inv_com((x+y)/3,z,MOD)<<endl;
}