#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

typedef unsigned long long ull;

const ull B1=1e8+7;
const ull B2=1e9+7;

bool rolling_hash(string const&S, int t_start, int m){
    int s_start = t_start + m;

    //B^mの準備
    ull pow_B_m1=1,pow_B_m2=1;
    rep(k,m){
        pow_B_m1*=B1, pow_B_m2*=B2;
    }
    //sとtの先頭m文字のハッシュ値sh, thを計算
    ull sh1=0, sh2=0, th1=0, th2=0;
    rep(k,m){
        th1=th1*B1+S[t_start + k], th2=th2*B2+S[t_start + k];
        sh1=sh1*B1+S[s_start + k], sh2=sh2*B2+S[s_start + k];
    }
    //sをずらしてハッシュ値を更新
    for(int k=0;s_start+k<S.length();k++){
        if(sh1==th1 && sh2==th2) return true;
        if(k+s_start<S.length()){
            sh1=sh1*B1+S[s_start+m+k]-S[s_start+k]*pow_B_m1;
            sh2=sh2*B2+S[s_start+m+k]-S[s_start+k]*pow_B_m2;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    string S;
    cin >> S;
    int ng=n+1, ok=0;
    while(ng-ok>1){
        int mid=(ng+ok)/2;
        bool matched=false;
        rep(i,n){
            if(i+mid*2>n) break;
            if(rolling_hash(S,i,mid)){
                matched=true;
                break;
            }
        }
        if(matched) ok=mid;
        else ng=mid;
    }
    cout << ok << endl;
    return 0;
}