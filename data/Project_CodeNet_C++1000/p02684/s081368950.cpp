#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i],--a[i];
    int now = 0;
    int cnt = 0;
    int cyc = 0;
    int s = 0;
    vector<int> before(n,-1);
    vector<int> res;
    while(1){
        res.push_back(now);
        before[now] = cnt;
        ++cnt;
        now = a[now];
        if(before[now]>=0){
            cyc = cnt - before[now];
            s = before[now];
            break;
        }
    }

    if(k <= s){ cout << res[k]+1 << endl;}
    else{
        cout << res[s+(k-s)%cyc]+1 << endl;
    }
    return 0;
}