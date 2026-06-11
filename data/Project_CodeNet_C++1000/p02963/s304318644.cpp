#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const double PI = acos(-1);
vector<P> edge[100005];
vl seen(100005,INFL);
int main(){
	ll s;cin>>s;
    ll x=1e9,y=1;
    ll yy= s/x+(s%x==0?0:1);
    ll xx= abs(s-x*yy);
    cout<<0<<' '<<0<<' ';
    cout<<x<<' '<<y<<' ';
    cout<<xx<<' '<<yy<<endl;
}