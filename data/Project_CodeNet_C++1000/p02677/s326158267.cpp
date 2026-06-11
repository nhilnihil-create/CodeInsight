#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

// cos p = (a*a+b*b-c*c) / 2ab
int main() {
    int a,b,h,m;
    cin>>a>>b>>h>>m;
    double l=360*(1.0*(h+1.0*m/60)/12),r=360*(1.0*m/60);
    double p=r-l;
    if(p<0) p=-p;
    if(p>180) p=360-p;
    cout<<fixed<<setprecision(10)<<sqrt(a*a+b*b-2*a*b*cos(p/360*2*acos(-1.0)))<<endl;
}