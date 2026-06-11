#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll min(ll a, ll b){
    if(a < b) return a;
    else return b;
}
ll max(ll a, ll b){
    if(a > b) return a;
    else return b;
}
int main(){
    cout << fixed << setprecision(10);
    ll n,a,b;
    cin >> n >> a >> b;
    if((b - a)%2 == 0){
        cout << (b - a)/2 << endl;
    }else{
        if(n -  a > b - 1){
            cout <<a  + (b - (a - 1) - 1)/2 << endl;
        }else{
            cout << n - b + 1 + (n - (a  + (n - b)) - 1)/2 << endl;
        }
    }
    return 0;
}