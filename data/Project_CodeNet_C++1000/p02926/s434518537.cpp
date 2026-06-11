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
typedef pair<ld, ld> LDP;

int n;
LDP vec[110];
vector<ld> ang_={(ld)0,pi,-pi},ang={(ld)0,pi,-pi};

void solve(){
    cin >> n;
    rep(i,n){
        int x,y;
        cin >> x >> y;
        vec[i]=P(x,y);
    }
    rep(i,n){
        ld a1,a2;
        a1=atan2(vec[i].second,vec[i].first)+pi/2;
        a2=atan2(vec[i].second,vec[i].first)-pi/2;
        if (a1>pi) a1-=pi;
        if (a2<-pi) a2+=pi;
        ang_.push_back(a1);
        ang_.push_back(a2);
        ang_.push_back(atan2(vec[i].second,vec[i].first));
        ang.push_back(a1);
        ang.push_back(a2);
        ang.push_back(atan2(vec[i].second,vec[i].first));
    }
    sort(ang_.begin(),ang_.end());
    rep(i,(int)ang_.size()-1){
        ang.push_back((ang_[i]+ang_[i+1])/2);
    }
    sort(ang.begin(),ang.end());
    ld ans=0;
    rep(i,ang.size()){
        ld a=ang[i];
        ld p=cos(a),q=sin(a);
        //cout << p << " " << q << endl;
        ld x=0,y=0;
        rep(k,n){
            //cout << p*vec[k].first+q*vec[k].second << endl;
            if (p*vec[k].first+q*vec[k].second>=0) {
                x+=vec[k].first;
                y+=vec[k].second;
            }
        }
        //cout << x << " " << y << endl;
        ans=max(ans,sqrt(x*x+y*y));
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}