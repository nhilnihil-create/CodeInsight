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
    deque<ll> A(N);
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
    sort(p.begin(),p.end());
    sort(m.begin(),m.end());
    vector<Pll> v;
    if(N == 2){
        cout << max(A[0],A[1]) - min(A[0],A[1]) << endl;
        cout << max(A[0], A[1]) << " " << min(A[0], A[1]) << endl;
        return 0;
    }
    rep(i,N-1){
        ll t1,t2;
        if(p.empty()){
            t1 = m.front();
            m.pop_front();
            t2 = m.back();
            m.pop_back();
            if(t1 > t2){
                v.push_back(Pll(t1,t2));
            }else{
                v.push_back(Pll(t2,t1));
            }
            p.push_back(abs(t1-t2));
        }else if(m.empty()){
            t1 = p.front();
            p.pop_front();
            t2 = p.back();
            p.pop_back();
            if(p.empty()){
                if(t1>t2){
                    v.push_back(Pll(t1,t2));
                }else{
                    v.push_back(Pll(t2,t1));
                }
                p.push_back(abs(t1-t2));
                continue;
            }else if(t1>t2){
                v.push_back(Pll(t2, t1));
            }else{
                v.push_back(Pll(t1, t2));
            }
            m.push_back(-abs(t1-t2));
        }else{
            t1 = p.back();
            p.pop_back();
            t2 = m.back();
            m.pop_back();
            if(p.empty()){
                v.push_back(Pll(t1,t2));
                p.push_back(t1-t2);
            }else{
                v.push_back(Pll(t2,t1));
                m.push_back(t2-t1);
            }
        }
    }
    cout << p.back() << endl;
    rep(i,N-1){
        cout << v[i].first << " " << v[i].second << endl;
    }
    /*
    rep(i,N-1){
        ll t1 = A.front();
        ll t2 = A.back();
        A.pop_front();
        A.pop_back();
        v.push_back(Pll(t2,t1));
        ll u = t2-t1;
        auto itr = lower_bound(A.begin(), A.end(), u);
        A.insert(itr, u);
    }
    cout << A[0] << endl;
    rep(i,N-1){
        cout << v[i].first << " " << v[i].second << endl;
    }
    /*
    bool pflag = true;
    bool mflag = true;
    rep(i,N){
        if(A[i] < 0){
            pflag = false;
            break;
        }
    }
    rep(i,N){
        if(A[i] >= 0){
            mflag = false; 
            break;
        }
    }
    ll ans = 0;
    vector<Pll> v;
    if(mflag || pflag){
        rep(i,N){
            A[i] = abs(A[i]);
        }
        sort(A.begin(), A.end());
        ans -= A[0];
        REP(i,1,N){
            ans += A[i];
        }
    }else{
        rep(i,N){
            ans += abs(A[i]);
        }
    }
    cout << ans << endl;*/
}