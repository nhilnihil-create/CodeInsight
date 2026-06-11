#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;


struct F2_mat{
    vector<ll> mat;
    F2_mat(vector<ll> mat):mat(mat){}

    void Gauss(){
        int n=mat.size(),pos=0;
        for(int i=63;i>=0;i--){
            ll k=(1ll << i);
            for(int j=pos;j<n;j++){
                //cout << bitset<5>(mat[j]) << endl;
                if (mat[j]&k) {
                    //cout << j << " " << pos << endl;
                    swap(mat[j],mat[pos]);
                    for(int l=0;l<n;l++){
                        //cout << l << endl;
                        //cout << bitset<60>(mat[l]) << endl;
                        if (l==pos) continue;
                        if (mat[l]&k) mat[l]^=mat[pos];
                    }
                    pos++;
                    break;
                }
            }
        }
    }
};

int n;
ll S;
vector<ll> a;

void solve(){
    cin >> n;
    rep(i,n){
        ll a_;
        cin >> a_;
        S^=a_;
        a.push_back(a_);
    }
    //cout << bitset<60>(S) << endl;
    ll ans=0;
    per(k,64){
        ll m=(1ll << k);
        if (S&m){
            rep(i,n){
                if (a[i]&m)a[i]^=m;
            }
        }
    }
    F2_mat MAT(a);
    MAT.Gauss();
    ll M=0;
    rep(i,n){
        //cout << bitset<60>(MAT.mat[i]) << endl;
        M^=MAT.mat[i];
    }
    cout << 2*M+S << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}