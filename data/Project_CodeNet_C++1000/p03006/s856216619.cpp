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
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    P pos[n];
    vector<P> vec;
    rep(i,0,n) cin >> pos[i].fs >> pos[i].sc;
    rep(i,0,n){
        rep(j,0,n){
            vec.push_back(P(pos[i].fs - pos[j].fs,pos[i].sc - pos[j].sc));
        }
    }

    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    
    ll ans = LINF;
    sort(pos,pos+n,greater<P>());
    rep(i,0,vec.size()){
        ll cnt = 1;
        ll memo = 1;
        P p = pos[0];
        bool is_used[n] = {false};
        is_used[0] = true;
        while(cnt < n){
            rep(j,0,n){
                if(!is_used[j] && p.fs - pos[j].fs == vec[i].fs && p.sc - pos[j].sc == vec[i].sc){
                    p = pos[j];
                    is_used[j] = true;
                    cnt++;
                    break;
                }
                else if(j == n-1){
                    rep(k,0,n){
                        if(!is_used[k]){
                            p = pos[k];
                            is_used[k] = true;  
                            cnt++;
                            memo++;
                            break;
                        }
                    }
                }
            }
        }

        ans = min(ans,memo);
    }
    cout << ans << endl;

    return 0;
}
