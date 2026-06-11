#include <bits/stdc++.h>
#include <complex>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,C,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
const long double EPS = 1e-9;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

vec a(100010);
ll row = 0;
void line_s(ll bit){
    ll id = -1;
    reps(i,row,N) if((a[i]>>bit)&1) id = i;
    //cout<<bit<<' '<<id<<endl;
    if(id == -1) return;
    swap(a[row], a[id]);
    rep(i,N) if((i != row) && (((a[i]>>bit)&1))) a[i] ^= a[row];
    ++row;
    return;
}

int main() {
    cin>>N;
    M = 0;
    rep(i,N) {
        cin>>a[i];
        M ^= a[i];
    }
    for(ll i = 59; i >= 0; --i) if((((M>>i)&1) == 0) && (row < N)) line_s(i);
    ll ans = 0;
    rep(i,row) ans ^= a[i];
    cout<<(ans|M)*2 - M<<endl;
    //cout<<M<<' '<<ans<<endl;
}
