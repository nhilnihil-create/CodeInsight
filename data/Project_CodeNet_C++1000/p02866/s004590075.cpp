#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using psl = pair<string, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 998244353
#define all(vec) vec.begin(), vec.end()

int main(){
    int n;
    cin >> n;
    vi d(n);
    rep(i,n) cin >> d.at(i);
    if(d.at(0) != 0){
        cout << 0 << endl;
        return 0;
    }
    sort(all(d));
    if(d.at(1) == 0){
        cout << 0 << endl;
        return 0;
    }
    vi cnt(n,0);
    rep(i,n) cnt.at(d.at(i))++;
    long ans = 1;
    vl num(n,1);
    for(int i=1;i<n;i++){
        num.at(d.at(i)) *= cnt.at(d.at(i)-1);
        num.at(d.at(i)) %= MOD;
    }
    rep(i,n){
        ans *= num.at(i);
        ans %= MOD;
    }
    cout << ans << endl;
}