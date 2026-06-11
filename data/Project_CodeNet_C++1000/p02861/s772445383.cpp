#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
ll MOD = 1000000007;
ll INF =1<<30;



int main(){
    int n;
    cin >> n;
    vector<int>d(n);
    rep(i,n){
        d[i] = i;
    }
    vector<int>x(n),y(n);
    rep(i,n)cin >> x[i]>>y[i];
    vector<double>ans;
    do{
        double dist = 0;
        rep(i,n-1){
            dist+=sqrt(((x[d[i]]-x[d[i+1]])*(x[d[i]]-x[d[i+1]])+
            (y[d[i]]-y[d[i+1]])*(y[d[i]]-y[d[i+1]])));
        }
        ans.push_back(dist);
    }while(next_permutation(d.begin(),d.end()));
    double tot = 0;
    rep(i,ans.size()){
        tot+=ans[i];
    }
    cout << fixed <<setprecision(8) << tot/ans.size() <<endl;
}