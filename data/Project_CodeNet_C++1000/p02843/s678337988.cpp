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
    ll x;
    cin >> x;
    if(x >= 2300){
        cout << 1 << endl;
        return 0;
    }

    rep(i,0,x/100+1){
        rep(j,0,x/101+1){
            rep(k,0,x/102+1){
                rep(l,0,x/103+1){
                    rep(m,0,x/104+1){
                        if(i*100+j*101+k*102+l*103+m*104 > x) break;
                        if((x-(i*100+j*101+k*102+l*103+m*104)) % 105 == 0){
                            cout << 1 << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << 0 << endl;
    return 0;
}