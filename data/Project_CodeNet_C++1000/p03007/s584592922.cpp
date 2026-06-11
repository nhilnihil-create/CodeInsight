#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    multiset<ll> s;
    rep(i,N){
        ll a;
        cin >> a;
        s.insert(a);
    }
    ll cnt;
    vector<Pll> ans(N-1);
    rep(i,N-1){
        ll a,b;
        if (i!=N-2){
            a=*s.begin();
            s.erase(s.begin());
            if (a<0){
                auto itr=s.lower_bound(0);
                if (itr==s.end()) itr=s.end(),--itr;
                b=*itr;
                s.erase(s.lower_bound(b));
                if (s.lower_bound(0)==s.end()) swap(a,b);
                s.insert(a-b);
            }
            else {
                auto itr=s.begin();
                b=*itr;
                s.erase(itr);
                s.insert(a-b);
            }
        }
        else {
            a=*s.rbegin(),b=*s.begin();
            cnt=a-b;
        }
        ans[i]=Pll(a,b);
    }
    cout << cnt << endl;
    rep(i,N-1) cout << ans[i].first << ' ' << ans[i].second << endl;
}