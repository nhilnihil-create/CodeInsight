#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
signed main(void){
    long double t1, t2; cin>>t1>>t2;
    long double a1,a2; cin>>a1>>a2;
    long double b1,b2; cin>>b1>>b2;
    if(t1*a1+t2*a2 == t1*b1+t2*b2) {cout<<"infinity"<<endl; return 0;}
    if(t1*a1+t2*a2<t1*b1+t2*b2){
        swap(a1,b1); swap(a2,b2);
    }
    int ans = 0;
    if(a1*t1 - b1*t1 < 0){
    long double p = t1*a1+t2*a2 - (t1*b1+t2*b2);
    long double x = max( (t1*a1 - t1*b1)/(-p), (t1*a1 - t1*b1)/(p));
    long double y = ceil(x);
    ans = y * 2;
    ans--;
    if( x == y) ans++;
    }
    cout<<ans<<endl;
}
