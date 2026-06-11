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
    ll N, K;
    cin >> N >> K;
    bool flag = false;
    //vector<vector<ll>> G(N,vector<ll>(N,1));
    vector<vector<ll>> G(N,vector<ll>(N,0));
    ll MM = 0;
    REP(i,1,N-1){
        MM += i;
    }
    if(K > MM){
        cout << -1 << endl;
        return 0;
    }
    rep(i,N-1){
        G[0][i+1] = 1;
        G[i+1][0] = 1;
    }
    cout << MM - K + N-1 << endl;
    ll cnt = 0;
    rep(i,N){
        REP(j,i+1,N){
            if(cnt == MM - K + N-1){
                flag = true;
                break;
            }
            cnt++;
            cout << i+1 << " " << j+1 <<endl;
        }
        if(flag) break;
    }
    /*
    rep(i,N){
        G[i][i] = 0;
    }
    ll cnt = 0;
    rep(i,N){
        REP(j,i+1,N){
            if(cnt == K){
                flag = true;
                break;
            }
            G[i][j] = 0;
            G[j][i] = 0;
            cnt++;
        }
        if(flag) break;
    }
    cout << (N*(N-1))/2 - K << endl;
    rep(i,N){
        REP(j,i+1,N){
            if(G[i][j]==0)continue;
            cout << i+1 <<" "<< j+1 << endl;
        }
    }
    /*
    ll s,t;
    REP(i,1,N){
        if(2*K == i*(i-1) + (N-i)*(N-i-1)){
            flag = true;
            s = i;
            t = N - i;
            break;
        }
    }
    if(K < N-1){
        flag = true;
    }
    if(!flag){
        cout << -1 << endl;
        return 0;
    }
    if(K >= N-1){
        cout << s*t << endl;
        REP(i,1,s+1){
            REP(j,s+1,N+1){
                cout << i << " " << j << endl;
            }
        }
    }else{
        cout << N*(N-1)/2 - K << endl;
        REP(i,1,N+1){
            REP(j,i+1,N+1){
                if(i == 1 && i > K) continue;
                cout << i << " " << j << endl;
            }
        }
    }*/
}