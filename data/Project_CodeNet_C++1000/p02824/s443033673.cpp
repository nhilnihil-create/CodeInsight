#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
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
    ll N,M,V,P;
    cin >> N >> M >> V >> P;
    vector<ll> A(N),S(N+1);
    rep(i,N){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    rep(i,N){
        S[i+1] = A[i] + S[i];
    }
    ll sc = M*V;
    ll cnt = 0;
    rep(i,N){
        sc = M*V;
        sc -= M*(i+1);
        sc -= M*(P-1);
        if(sc <= 0){
            if(A[i] + M >= A[N-P]){
                //cout << "b " << A[i] <<endl;
                cnt++;
            }
        }else{
            /*
            ll sum = S[N-P+1] - S[i+1];
            sum += sc;
            ll n = N-P - i;
            ll t = sum / n;
            */
            ll t = 0;
            //bool flag = false;
            ll p = A[i] + M;
            if(p - A[N-(P-1)-1] < 0) continue;
            /*for(ll j=i+1; j<N-(P-1); j++){
                t = p - A[j];
                sc -= t;
            }*/
            sc -= p*(N-(P-1)-(i+1)) -  (S[N-P+1] - S[i+1]);
            //if(flag) continue;
            //cout << "c " << A[i] << endl;
            if(sc > 0){
                continue;
            }
            //cout << "a " << A[i] << endl;
            cnt++;
        }
        sc = M*V;
    }
    cout << cnt << endl;
}   