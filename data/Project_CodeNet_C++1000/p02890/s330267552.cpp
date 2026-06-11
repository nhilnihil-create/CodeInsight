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

int n;
int a[300010],b[300010],c[300010],S[300010],T[300010],ans[300010];

void solve(){
    cin >> n;
    rep(i,n){
        cin >> a[i];
        b[a[i]]+=1;
    }
    rep(i,n+1){
        c[b[i]]+=1;
    }
    rep(i,n){
        S[i+1]+=S[i]+c[i+1];
        T[i+1]+=T[i]+(i+1)*c[i+1];
    }
    vector<int> f;
    f.push_back(n);
    Rep(i,1,n+1){
        f.push_back((T[max(0,i-1)]+i*(S[n]-S[max(0,i-1)]))/i);
        //cout << f[i] << " ";
    }
    //cout << "" << endl;
    int l=n;
    Rep(k,1,n+1){
        while(k>f[l]){
            l--;
        }
        cout << l << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}