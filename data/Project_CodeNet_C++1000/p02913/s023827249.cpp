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
    string S,SS;
    cin >> N >> SS;
    ll ans = 0;
    rep(ii,N){
        S = SS.substr(ii,N-ii);
        vector<ll> A(S.size());
        A[0] = S.size();
        int i = 1, j = 0;
        while (i < S.size()) {
            while (i+j < S.size() && S[j] == S[i+j]) ++j; // 右向きにjを伸ばしていく
            A[i] = j;
            if (j == 0) { ++i; continue;}
            int k = 1;
            while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k; // i~j間にkを走らせる
            i += k; j -= k;
        }
        REP(l,1,A.size()){
            if(A[l] > l) continue;
            cmax(ans,A[l]);
        }
    }
    cout << ans << endl;
}