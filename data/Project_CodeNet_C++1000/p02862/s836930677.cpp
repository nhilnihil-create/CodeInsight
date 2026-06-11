#include<bits/stdc++.h>
using namespace std;

#define     int long long
#define     pii pair<int,int>
#define     x first
#define     y second
#define     __FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define     MOD 1000000007
#define     INF 100000000
#define     nll cout << "\n"
#define     nl "\n"
#define     MAX 1000003
#define     print(v) cout << v << " "
#define     dbgv(v) cout << v << nl
#define     asdf(v) cout << v << nl
#define     pasdf(p) cout << p.x << " " << p.y << nl
#define     dbg cout << "dbg\n"
#define     vi vector<int>
#define     vl vector<ll>
#define     pb push_back
#define     con continue

int xx[] = {1, -1, 0, 0};
int yy[] = {0, 0, -1, 1};

int factorial[MAX];
int iFactorial[MAX];

int bigMod(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = (ans*a)%MOD;
        }
        a = (a*a)%MOD;
        b >>= 1;
    }
    return ans%MOD;
}

void pro(){
    factorial[0] = 1;
    iFactorial[0] = 1;
    for(int i = 1; i < MAX; i++){
        factorial[i] = (factorial[i-1]*i)%MOD;
        iFactorial[i] = (iFactorial[i-1]*bigMod(i, MOD-2))%MOD;
    }
}

int ncr(int n, int r){
    if(n < r)return 0;
    int ans = factorial[n];
    ans = (ans*iFactorial[r])%MOD;
    ans = (ans*iFactorial[n-r])%MOD;
    return ans;
}

int32_t main(){
    pro();
    int x, y;
    while(cin >> x >> y){
       if((x+y)%3 > 0){
            asdf("0"); con;
       }
       int big = (2*y - x)/3;
       int small = (2*x-y)/3;
       int total = big+small;
       if(big < 0 || small < 0){
            asdf(0); con;
       }
       asdf(ncr(total, big));
    }
    return 0;
}
