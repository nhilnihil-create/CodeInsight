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
    vector<ll> A(N), b(1000000+1,0), cc(1000001);
    rep(i,N){
        cin >> A[i];
    }
    bool flag = false;
    REP(i,2,1000001){
        ll cur = i;// A[i];
        //cout << i << endl;
        if(b[i] != 0){
            continue;
        }
        while(cur <= 1000000){
            b[cur] = i;
            cur += i;
        }
    }
    b[0] = 1;
    b[1] = 1;
    //PR(b,1000);
    rep(i,N){
        if(A[i] == 1)continue;
        ll n = A[i];
        vector<pair<ll,int>> res;
        while(n > 1){
            ll p = b[n];
            res.emplace_back(p,0);
            while(n % p == 0){
                n /= p;
                res.back().second++;
            }
        }
        for(auto& e:res){
            cc[e.fi]++;
        }
    }
    rep(i,1000001){
        if(cc[i] > 1){
            flag = 1;
            break;
        }
    }
    if(!flag){
        cout << "pairwise coprime" << endl;
        return 0;
    }
    ll c=A[0];
    rep(i,N){
        c = __gcd(c,A[i]);
    }
    if(c==1){
        cout << "setwise coprime" << endl;
    }else{
        cout << "not coprime" << endl;
    }
}