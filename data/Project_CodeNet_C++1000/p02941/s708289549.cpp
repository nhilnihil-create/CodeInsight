#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
using namespace std;

int MOD = 998244353;
// int MOD = 1000000007;

int ok[200010] = {0};
int ok_cnt = 0;

signed main(){

    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];

    queue<ll> q;
    rep(i,n){
        if(b[i] > b[(i-1+n)%n] + b[(i+1)%n] && b[i] != a[i]){
            q.push(i);
        }
    }
    // while(q.size()){
    //     cerr << q.front() << endl;
    //     q.pop();
    // }

    int ans = 0;
    while(q.size()){
        ll i = q.front();
        q.pop();

        if((b[i]-a[i])%(b[(i-1+n)%n] + b[(i+1)%n]) == 0){
            ans += (b[i]-a[i])/(b[(i-1+n)%n] + b[(i+1)%n]);
            b[i] = a[i];
        }else{
            ll k = (b[i]-1)/(b[(i-1+n)%n] + b[(i+1)%n]);
            ans += k;
            b[i] -= k*(b[(i-1+n)%n] + b[(i+1)%n]);
        }

        if(b[(i-1+n)%n] > b[(i-2+n)%n] + b[i] && b[(i-1+n)%n] != a[(i-1+n)%n])q.push((i-1+n)%n);
        if(b[(i+1)%n] > b[i] + b[(i+2)%n] && b[(i+1)%n] != a[(i+1)%n])q.push((i+1)%n);

        
        // ll k = (b[i]-a[i])/(b[(i-1+n)%n] + b[(i+1)%n]);
        // b[i] -= k*(b[(i-1+n)%n] + b[(i+1)%n]);
        // ans += k;
        // if(a[i] == b[i])ok_cnt++;

        // if(b[(i-1+n)%n] - b[(i-2+n)%n] - b[i] >= a[(i-1+n)%n])q.push((i-1+n)%n);
        // if(b[(i+1)%n] - b[i] - b[(i+2)%n] >= a[(i+1)%n])q.push((i+1)%n);
    }
    // rep(i,n)cerr << a[i] << " ";cerr << endl;
    // rep(i,n)cerr << b[i] << " ";cerr << endl;
    // if(ok_cnt != n)cout << -1 << endl;
    // else cout << ans << endl;

    rep(i,n){
        if(a[i] != b[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;



   
    

    return 0;
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://cf17-final-open.contest.atcoder.jp/tasks/cf17_final_a
// rm -r -f test;oj dl http://agc037.contest.atcoder.jp/tasks/agc037_a
