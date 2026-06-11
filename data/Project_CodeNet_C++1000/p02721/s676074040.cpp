#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1 << 30;
int main(){
    int n,k,c;
    string s;
    cin >> n >> k >> c >> s;
    vector<int> front(n), back(n); //front[i]: 0-iまでで最大何日働けるか
    int next = -1;
    int now = 0;
    rep(i,n){
        if(s[i]=='o') {
            if(i>=next){
                next = i+c+1;
                now++;
            }
        }
        front[i] = now;

    }
    next = INF;
    now = 0;
    for(int i=n-1; i>=0; i--){
        if(s[i]=='o'){
            if(i<=next){
                next = i-c-1;
                now++;
            }    
        }
        back[i] = now;
    }
    rep(i,n){
        int mx = 0;
        if(i>0) mx += front[i-1];
        if(i<n-1) mx += back[i+1];
        if(mx<k) cout << i+1 << endl;
    }
    
    return 0;
}