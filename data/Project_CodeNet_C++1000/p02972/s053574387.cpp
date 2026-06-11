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

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N+1),b(N+1),c;
    REP(i,1,N+1){
        cin >> a[i];
    }
    for(ll i=N;0<i;i--){
        ll sum = 0;
        ll ind = i;
        while(ind <= N){
            sum += b[ind];
            ind += i;
        }
        if((sum % 2) != a[i]){
            b[i] = 1;
            c.push_back(i);
        }
    }
    if(c.size()>0){
        cout << c.size() << endl;
        PR(c,c.size());
    }else{
        cout << 0 << endl;
    }
}