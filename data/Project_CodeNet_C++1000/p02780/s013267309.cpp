#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 200000000000
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
    ll N,K;
    cin >>N>>K;
    vector<long double> p(N);
    vector<long double> sum(N+1);
    rep(i,N){
        cin>>p[i];
    }
    sum[0] = 0;
    sum[1] = (1+p[0])/2.0;
    rep3(i,2,N+1){
        sum[i] = sum[i-1] + (1+p[i-1])/2.0;
    }


    long double ans = 0.0;
    rep(i,N-K+1){
        chmax(ans,sum[i+K]-sum[i]);
    }
    cout << fixed << setprecision(15) << ans << endl;



    return 0;
    

}