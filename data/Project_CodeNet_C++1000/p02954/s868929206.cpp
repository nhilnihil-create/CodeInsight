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

#include <bits/stdc++.h>
#define rep(i,a,n) for(ll i = a;i < n;i++)
typedef long long ll;
using namespace std;


int main(){ 
    string s;
    cin >> s;
    ll n = (ll)s.size();

    ll cnt[n] = {};
    ll r_cnt = 0;
    rep(i,0,n-1){
        if(s[i] == 'R') r_cnt++;

        if(s[i] == 'R' && s[i+1] == 'L'){
            cnt[i] += ceil(r_cnt/2.0);
            cnt[i+1] += r_cnt - ceil(r_cnt/2.0);
            r_cnt = 0;
        }

    }

    ll l_cnt = 0;
    rep(i,0,n-1){
        if(s[n-i-1] == 'L') l_cnt++;

        if(s[n-i-2] == 'R' && s[n-i-1] == 'L'){
            cnt[n-i-1] += ceil(l_cnt/2.0);
            cnt[n-i-2] += l_cnt - ceil(l_cnt/2.0);
            l_cnt = 0;
        }
    }

    rep(i,0,n){
        cout << cnt[i] << ((i == n-1)? "\n": " ");
    }

}
