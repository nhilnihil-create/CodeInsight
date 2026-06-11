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
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N,M;
    string S;
    cin >> N >> M;
    cin >> S;
    vector<ll> vs(N+1),dp(N+1);
    rep(i,N+1){
        if(S[i]=='0'){
            vs[i] = 0;
        }else{
            vs[i] = 1;
        }
    }
    ll cur = N;
    vector<ll> ans;
    while(1){
        bool flag = true;    
        for(ll i = M; i>0;i--){
            if(cur-i <= 0){
                ans.push_back(cur);
                goto  gt;
            }
            if(vs[cur-i] == 0){
                ans.push_back(i);
                cur -= i;
                flag = false;
                break;
            }
        }
        if(flag){
            cout << -1 << endl;
            return 0;
        }
    }
    gt:
    reverse(ans.begin(), ans.end());
    PR(ans, ans.size());
}