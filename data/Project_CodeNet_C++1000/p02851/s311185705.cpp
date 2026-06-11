//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};


int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
        rep(i,n) cin>>a.at(i);
        rep(i,n) a[i] %=k;
    vector<int> sum(n,0);
    sum[0]=a[0];
    rep(i,n-1) sum[i+1]=(a[i+1]+sum[i])%k;
    rep(i,n){
        sum[i]=(i+1)-sum[i]+k;
        sum[i] %= k;
    }
    unordered_map<int,in> x;
    rep(i,min(n,k-1)) x[sum[i]] ++;
    int key=0;
    in ans=0;
    rep(i,n){
        ans += x[key];
        key ++;
        key -= a[i];
        key += k;
        key %= k;
        x[sum[i]] --;
        if(i+k<=n) x[sum[i+k-1]] ++;
    }
    cout<<ans<<endl;
}/*
./problem.exe
*/