#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n, cnt=0;
    string s;
    cin >> n >> s;
    rep(i,1000){
        ll num[3] = {i/100, (i/10)%10, i%10};
        ll id = 0;
        rep(j,n){
            if(s[j] == num[id] + '0') id++;
            if(id == 3) break;
        }
        if(id == 3) cnt++;
    }
    cout << cnt << endl;
    return 0;
}