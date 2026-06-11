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
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin >> N;
    typedef complex<long double> cpx;
    vector<cpx> V(N);
    cpx sum = cpx(0, 0);
    rep(i,N) {
        long double a, b;
        cin>>a>>b;
        V[i] = cpx(a, b);
        sum += V[i];
    }
    vec ord(N);
    rep(i,N) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](ll x, ll y){
        return arg(V[x]) < arg(V[y]);
    });
    /*rep(i,N) {
        long double a = V[ord[i]].real(), b = V[ord[i]].imag();
        cout<<a<<' '<<b<<endl;
    }*/
    long double ans = 0;
    rep(i,N) {
        reps(j,i,N+1){ //区間[i,j)およびその逆方向
            cpx temp = cpx(0, 0);
            reps(k,i,j) temp += V[ord[k]];
            ans = max(ans, temp.real()*temp.real() + temp.imag()*temp.imag());
            temp = sum - temp;
            ans = max(ans, temp.real()*temp.real() + temp.imag()*temp.imag());
        }
    }
    cout<<fixed<<setprecision(15)<<sqrt(ans)<<endl;
}