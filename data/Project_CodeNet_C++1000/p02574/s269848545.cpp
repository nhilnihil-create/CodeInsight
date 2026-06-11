#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define USE_LLONG_AS_INT
#ifdef USE_LLONG_AS_INT
#define int long long
#define inf (1ll<<60)
#else
#define inf (1<<30)
#endif
#define rep(i,n) for(int i=0;i<(n);i++)
#define Rep(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define rev(i,n) for(int i=(n)-1;i>=0;i--)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pb push_back
#define eb emplace_back
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define MEMSET(a) memset(a,0,sizeof(a))
#define Yes(f) cout<<(f?"Yes":"No")<<endl
#define yes(f) cout<<(f?"yes":"no")<<endl
#define YES(f) cout<<(f?"YES":"NO")<<endl
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v), greater<int>())

using namespace std;

const int mod=1e9+7;
// const int mod=998244353;
const string sp=" ";

void run();

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
}

signed main(){
    init();
    run();
    return 0;
}

int c[1000001];

void run(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,n)cin>>a[i],c[a[i]]++;
    int m=*max_element(all(a));
    bool p=true;
    REP(i,2,m){
        int t=0;
        for(int j=i;j<=m;j+=i)t+=c[j];
        p&=t<=1;
    }
    if(p){
        cout<<"pairwise coprime"<<endl;
        return;
    }
    int g=a[0];
    rep(i,n)g=gcd(g,a[i]);
    cout<<(g==1?"setwise":"not")<<" coprime"<<endl;
}