#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll mod=1e9+7;


int main()
{
    ll n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<ll> ans;
    vector<pll> info(n+1);
    ll cnt=0;
    rep(i,n+1){
        if(i==0){
            cnt++;
            info[i]=make_pair(0,cnt);
            continue;
        }
        if(s[i-1]==s[i]){
            cnt++;
            if(s[i]=='0'){
                info[i]=make_pair(0,cnt);
            }
            else{
                info[i]=make_pair(1,cnt);
            }
        }
        else{
            if(s[i]=='0'){
                cnt=1;
                info[i]=make_pair(0,cnt);
            }
            if(s[i]=='1'){
                cnt=1;
                info[i]=make_pair(1,cnt);
            }
        }
    }
    ll able_move=m;
    bool ok=true;
    for(ll i=n;i>=0;i--){
        if(i==0){
            if(able_move!=m){
                ans.push_back(m-able_move);
            }
            
            break;
        }
        if(info[i].fi==0 && info[i-1].fi==1){
            if(info[i-1].se+1>m){
                ok=false;
                break;
            }
            if(info[i-1].se+1<=able_move){
                able_move--;
            }
            else{
                ans.push_back(m-able_move);
                able_move=m;
                able_move--;
            }
        }
        else{
            able_move--;
        }
        if(able_move==0){
            ans.push_back(m);
            able_move=m;
        }
    }
    if(!ok){
        cout << -1 << endl;
        return 0;
    }
    ll t=ans.size();
    for(ll i=t-1;i>=0;i--){
        if(i==t-1){
            cout << ans[i];
        }
        else{
            cout << " " << ans[i];
        }
    }
    cout << endl;
    return 0;
} 