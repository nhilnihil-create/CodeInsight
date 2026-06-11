#include <bits/stdc++.h>
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

ll N,M,H,W,K,Q,A,B,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin>>N;
    mat a(N-1,vec(0));
    ll level = 1;
    rep(i,N - 1){
        if((i + 1) == (1LL << level)) ++level;
        rep(j,i+1){
            if(j < (1LL << (level - 1))){
                a[j].push_back(level);
            }else{
                a[j].push_back(a[j - (1LL << (level - 1))][a[j].size()]);
            }
        }
    }
    rep(i,N-1){
        rep(j,a[i].size()){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}
