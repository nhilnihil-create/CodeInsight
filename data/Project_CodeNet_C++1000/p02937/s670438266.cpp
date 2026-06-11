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
    string S,T;
    cin >> S >> T;
    ll N = S.size();
    ll M = T.size();
    vector<vector<ll>> v(26);
    rep(i,N){
        v[S[i] - 'a'].push_back(i);
    }
    rep(i,N){
        v[S[i] - 'a'].push_back(i+N);
    }
    ll ans = 0;
    ll tmp = 0;
    rep(i,M){
        ll c = T[i] - 'a';
        if(v[c].size() == 0){
            cout << -1 << endl;
            return 0;
        }
        tmp = *lower_bound(v[c].begin(), v[c].end(), tmp)+1;
        if(tmp >= N){
            tmp -= N;
            ans += N;
        }
    }
    ans += tmp;
    cout << ans << endl;
}
    /*
    rep(i,M){
        if(v[T[i] - 'a'].size() == 0){
            cout << -1 << endl;
            return 0;
        }
        tmp = v[T[i] - 'a'].front();
        v[T[i] - 'a'].pop();
        if(ans < tmp){
            ans = tmp;
            v[T[i] - 'a'].push(tmp);        
        }else{
            bool flag = false;
            if(ans-tmp < N){
                rep(j,v[T[i] - 'a'].size()){
                    v[T[i] - 'a'].push(tmp);        
                    tmp = v[T[i] - 'a'].front();
                    v[T[i] - 'a'].pop();
                    if(ans < tmp){
                        ans = tmp;
                        v[T[i] - 'a'].push(tmp);
                        flag = true;
                        break;
                    }
                }
            }
            if(flag)continue;
            ll q = (ans-tmp)/N + 1;
            ans = tmp + q*N;
            v[T[i] - 'a'].push(tmp);        
        }
    }
    cout << ans+1 << endl;
}*/