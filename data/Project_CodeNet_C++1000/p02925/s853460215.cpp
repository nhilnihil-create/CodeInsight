#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
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
    vector<vector<ll>> A(N,vector<ll>(N-1));
    rep(i,N){
        rep(j,N-1){
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    vector<queue<ll>> que(N);
    rep(i,N){
        rep(j,N-1){
            que[i].push(A[i][j]);
        }
    }
    ll ans = 0;
    ll cnt = 0;
    rep(j,N*(N-1)/2){
        ans++;
        vector<ll> mp(N,0);
        bool flag = false;
        rep(i,N){
            if(mp[i] > 0) continue;
            if(que[i].empty()) continue;
            ll t = que[i].front();
            if(mp[t] > 0) continue;
            if(que[t].front() == i){
                flag = true;
                que[i].pop();
                que[t].pop();
                mp[i]++;
                mp[t]++;
                cnt++;
            }else{
                continue;
            }
        }
        //cout << ans << " " << cnt << endl;
        if(!flag){
            bool flag2 = false;
            rep(i,N){
                if(!que[i].empty())flag2 = true;
            }
            if(flag2){
                cout << -1 << endl;
                return 0;
            }else{
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
}