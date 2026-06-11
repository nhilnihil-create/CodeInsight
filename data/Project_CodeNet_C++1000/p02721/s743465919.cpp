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
    ll N,K,C;
    string S;
    cin >> N >> K >> C;
    cin >> S;
    ll cnt = 0;
    vector<ll> v(N, -1);
    rep(i,N){
        if(cnt >= K){
            break;
        }
        if(S[i] == 'o'){
            //S[i] = 'a';
            cnt++;
            v[i] = cnt;
            i += C;
            continue;
        }
    }
    if(cnt < K){
        cout << endl;
        return 0;
    }
    //PR(v,N);
    cnt = K;
    vector<ll> ans;
    for(ll i=N-1;i>=0;i--){
        if(cnt <= 0){
            break;
        }
        if(S[i] == 'o'){
            if(v[i] > 0){
                //cout << i << endl;
                if(v[i] == cnt){
                    ans.push_back(i+1);
                }
            }
            //S[i] = 'x';
            i -= (C);
            cnt--;
            continue;
        }
    }
    if(cnt > 0){
        cout << endl;
        return 0;
    }
    sort(ans.begin(), ans.end());
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
}