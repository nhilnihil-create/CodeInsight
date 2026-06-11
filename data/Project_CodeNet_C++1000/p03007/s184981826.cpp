#include <bits/stdc++.h>
//#include <atcoder/all>
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
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;
//using namespace atcoder;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    deque<ll> m,p;
    rep(i,N){
        if(A[i] >= 0){
            p.push_back(A[i]);
        }else{
            m.push_back(A[i]);
        }
    }
    ll sum = 0;
    vector<Pll> ans;
    sort(m.rbegin(), m.rend());
    sort(p.begin(), p.end());
    while(1){
        if(p.size() + m.size() <= 2) break;
        if(!p.empty() && !m.empty()){
            ll pp = p.front();
            ll mm = m.front();
            p.pop_front();
            m.pop_front();
            if(m.empty()){
                m.push_back(mm - pp);
                ans.push_back({mm,pp});
            }else{
                p.push_back(pp - mm);
                ans.push_back({pp,mm});
            }
        }else if(p.empty()){
            ll m1 = m.front();
            m.pop_front();
            ll m2 = m.front();
            m.pop_front();
            p.push_back(m1-m2);
            ans.push_back({m1,m2});
        }else{
            ll p1 = p.front();
            p.pop_front();
            ll p2 = p.front();
            p.pop_front();
            m.push_back(p1-p2);
            ans.push_back({p1,p2});
        }
    }
    cout << p.front() - m.front() << endl;
    ans.push_back({p.front(), m.front()});
    rep(i,ans.size()){
        cout << ans[i].fi << " " << ans[i].se << endl;
    }
}