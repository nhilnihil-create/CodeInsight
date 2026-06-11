#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 200000000000
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()

bool compare(pair<ll, string> a, pair<ll, string> b) {
    if(a.first != b.first){
        return a.first > b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
    ll N;
    cin >>N;
    vector<string> S(N);
    vector<pair<ll,string>> lis;
    map<string,ll> m;
    ll kind = 1;
    rep(i,N){
        cin >>S[i];
        if(m[S[i]] == 0){
            lis.pb(make_pair(1,S[i]));
            m[S[i]] = kind;
            kind++;
        }else{
            lis[m[S[i]]-1].first++;
        }
    }

    sort(all(lis),compare);
    //reverse(all(lis));
    ll mx = lis[0].first;
    cout << lis[0].second << endl;
    rep2(i,N-1){
        if(lis[i].first == mx){
            cout << lis[i].second << endl;
        }else{
            break;
        }
    }
    //cout << N << endl;


    return 0;
    

}