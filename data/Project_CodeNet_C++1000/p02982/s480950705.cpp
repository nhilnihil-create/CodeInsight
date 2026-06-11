#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
ll MOD = 1000000007;
ll INF =1<<30;


int x[11][11];
bool digi(int x){
    for(int i = 1;i*i<=x;++i){
        if(x%i==0){
            if(x/i==i) return true;
        }
    }
    return false;
}
int main(){
    int n,d;
    cin >> n >>d;
    rep(i,n){
        rep(j,d){
            cin >> x[i][j];
        }
    }
    int cnt = 0;
    rep(i,n-1){
        for(int k =i+1;k<n;++k){
        int y = 0;
        rep(j,d){
            y+=(x[i][j]-x[k][j])*(x[i][j]-x[k][j]);
        }
        if(digi(y)) cnt++;
        }
        
    }
    cout << cnt <<endl;
}