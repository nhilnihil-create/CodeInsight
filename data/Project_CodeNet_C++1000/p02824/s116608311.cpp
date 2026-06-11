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

int n,v,p;
ll m,a[100010];

void solve(){
    cin >> n >> m >> v >> p;
    rep(i,n){
        cin >> a[i];
    }
    sort(a,a+n,greater<ll>());
    //rep(i,n) cout << a[i] << " ";
    //cout << "" << endl;
    int ok=0,ng=n;
    while(ng-ok>=2){
        //cout << ok << " " << ng << endl;
        int mid =(ok+ng)/2;
        if (mid<=p-1) {
            ok=mid;
            continue;
        }
        ll s=v-p-n+mid+1;
        if (s<=0){
            if (a[p-1]<=a[mid]+m) ok=mid;
            else ng=mid;
        } 
        else{
            if (a[p-1]>a[mid]+m) {
                ng=mid;
                continue;
            }
            ll S=0;
            Rep(l,p-1,mid){
                S+=min(m,a[mid]+m-a[l]);
            }
            //cout << S << "," << s*m << endl;
            if (S>=s*m) ok=mid;
            else ng=mid;
        }
    }
    cout << ok+1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}