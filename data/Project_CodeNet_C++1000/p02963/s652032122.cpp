#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<62;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    ll S; cin >> S;
    vector<ll> X(3,0);
    vector<ll> Y(3,0);

    X[1] = 1e9;
    X[2] = 1;

    Y[2] = (S+(X[1]-1))/X[1];
    Y[1] = X[1]*Y[2]-S;

    cout << X[0] << " " << Y[0] << " ";
    cout << X[1] << " " << Y[1] << " ";
    cout << X[2] << " " << Y[2] << endl;    
    
}