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

const ll INF=1e18;
const ll mod=1e9+7;

int main(){
    ll t1,t2,a1,a2,b1,b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    if(a1*t1+a2*t2==b1*t1+b2*t2){
        cout << "infinity" << endl;
        return 0;
    }
    if(a1<b1 && a2<b2){
        cout << 0 << endl;
        return 0;
    }
    if(a1>b1 && a2>b2){
        cout << 0 << endl;
        return 0;
    }
    if(a1>b1 && a2<b2){
        swap(a1,b1);
        swap(a2,b2);
    }
    if(a1<b1 && a2>b2 && a1*t1+a2*t2<b1*t1+b2*t2){
        cout << 0 << endl;
        return 0;
    }
    ll d1=(a1-b1)*t1,d2=(a2-b2)*t2;
    ll d=d1+d2;
    ll ans=(-d1-1)/d;
    ans++;
    if(-d1%d==0){
        cout << 2*ans << endl;
    }
    else{
        cout << 2*ans-1 << endl;
    }
    
    return 0;
}
