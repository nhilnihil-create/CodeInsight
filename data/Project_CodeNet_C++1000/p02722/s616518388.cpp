#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

vector<ll> pickdiv(ll n){
    vector<ll> res;
    for(ll i=1; i*i <=n;i++){
        if(n%i)continue;
        res.emplace_back(i);
        ll q = n/i;
        if(q != i){
            res.emplace_back(q);
        }
    }
    return res;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> v = pickdiv(N);
    vector<ll> u = pickdiv(N-1);
    //ll ans = 0;
    map<ll,ll> mp;
    for(auto& k:v){
        if(k == 1) continue;
        ll cur = N;
        while(cur >= 1){
            if(cur % k == 0){
                cur /= k;
            }else if(cur % k == 1){
                mp[k]++;
                break;
            }else{
                break;
            }
        }
    }
    for(auto& k:u){
        if(k == 1) continue;
        ll cur = N;
        while(cur >= 1){
            if(cur % k == 0){
                cur /= k;
            }else if(cur % k == 1){
                mp[k]++;
                break;
            }else{
                break;
            }
        }
    }
    cout << mp.size() << endl;
    /*REP(k,3,M+1){
        ll cur = N;
        while(cur >= 1){
            if(cur % k == 0){
                cur /= k;
            }else if(cur % k == 1){
                ans++;
                break;
            }else{
                break;
            }
        }
    }
    cout << ans << endl;*/
}