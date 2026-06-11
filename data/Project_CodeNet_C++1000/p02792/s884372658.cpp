#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second


int main(){
    ll n;
    cin >> n;
    ll cnt[9][9] = {}; //iから始まってjで終わる数の個数
    rep(i,1,n+1){
        ll temp = i;
        string t = "";
        while(temp){
            t += (temp % 10) + '0';
            temp /= 10;
        }
        if(t[0] == '0' || t[t.size()-1] == '0') continue;
        cnt[t[t.size()-1] - '1'][t[0] - '1']++;
    }

    ll ans = 0;
    rep(i,1,n+1){
        ll temp = i;
        string t = "";
        while(temp){
            t += (temp % 10) + '0';
            temp /= 10;
        }
        if(t[0] == '0' || t[t.size()-1] == '0') continue;
        ans += cnt[t[0] - '1'][t[t.size()-1] - '1'];
    }
    cout << ans << endl;

    return 0;
}
