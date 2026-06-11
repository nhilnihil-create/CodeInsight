#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N;
    cin >> N;
    vector<vector<Pll>> P(N);
    ll a;
    ll x,y;
    rep(i,N){
        cin >> a;
        rep(j,a){
            cin >> x >> y;
            x--;
            P[i].push_back(Pll(x,y));
        }
    }
    ll ans = 0;
    rep(i,1LL << N){
        vector<ll> v;
        ll cnt = 0;
        bool flag = false;
        rep(j,N){
            if((i>>j) & 1LL){
                v.push_back(j);
                cnt++;
            }
        }
        for(auto& e:v){
            for(auto& p:P[e]){
                ll n = p.first;
                ll m = p.second;
                if(m==1 && ((i>>n)&1LL)==0 ){
                    flag = true;
                    break;
                }else if(m==0 && ((i>>n)&1LL)==1 ){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag){
            cmax(ans,cnt);
        }
    }
    cout << ans << endl;
}