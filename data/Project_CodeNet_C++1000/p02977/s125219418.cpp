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
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int n,c=0;
bool flag=false;

void solve(){
    cin >> n;
    int n_=n;
    while (n_>1){
        if (n_%2==1) flag=true;
        n_/=2;
        c+=1;
    }
    if (!flag) {
        cout << "No" << endl;
        return;
    }
    vector<P> ans;
    ans.push_back(P(3,n+1));
    for(int i=2;i<n;i+=2){
        ans.push_back(P(i,i+1));
        ans.push_back(P(1,i));
        ans.push_back(P(i+n+1,1));
        ans.push_back(P(i+n,i+n+1));
    }
    if (n%2==0) {
        ans.push_back(P(n,1<<c));
        int a=n^(1<<c);
        ans.push_back(P(2*n,a+n+1));
        //cout << a << endl;
    }

    cout << "Yes" << endl;
    rep(i,ans.size()) cout << ans[i].first << " " << ans[i].second << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}