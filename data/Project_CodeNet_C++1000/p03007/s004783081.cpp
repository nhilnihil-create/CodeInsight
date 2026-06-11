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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    deque<ll> mv, pv;
    vector<Pll> ansv;
    rep(i,N){
        if(A[i]>0){
            pv.push_back(A[i]);
        }else{
            mv.push_back(A[i]);
        }
    }
    sort(pv.begin(), pv.end());
    sort(mv.rbegin(), mv.rend());
    ll M = 0;
    rep(i,N-2){
        if(mv.empty()){
            ll p1 = pv.front();
            pv.pop_front();
            ll p2 = pv.front();
            pv.pop_front();
            mv.push_back(p1-p2);
            ansv.push_back(Pll(p1,p2));
        }else if(mv.size() > 1 && !pv.empty()){
            ll m1 = mv.front();
            mv.pop_front();
            ll p1 = pv.front();
            pv.pop_front();
            pv.push_back(p1-m1);
            ansv.push_back(Pll(p1,m1));
        }else if(mv.size() > 1 && pv.empty()){
            ll m1 = mv.front();
            mv.pop_front();
            ll m2 = mv.front();
            mv.pop_front();
            pv.push_back(max(m1,m2) - min(m1,m2));
            ansv.push_back(Pll(max(m1,m2), min(m1,m2)));
        }else{
            ll m1 = mv.front();
            mv.pop_front();
            ll p1 = pv.front();
            pv.pop_front();
            mv.push_back(m1-p1);
            ansv.push_back(Pll(m1,p1));
        }
    }
    ll p1 = pv.front();
    ll m1 = mv.front();
    ansv.push_back(Pll(p1,m1));
    cout << p1-m1 << endl; 
    rep(i,N-1){
        cout << ansv[i].fi << " " << ansv[i].se << endl;
    }
}