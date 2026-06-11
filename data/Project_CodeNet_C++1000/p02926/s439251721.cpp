#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef pair<ll,ll> P;
typedef map<ll,ll> MP;
typedef priority_queue<ll> PQ;
typedef stack<ll> ST;
typedef queue<ll> QUE;
#define pb push_back
#define st first
#define nd second
#define SZ(x) ((int)(x).size())
#define FOR(i,s,n) for(int i=(int)(s); i< (int)(n); i++)
#define rep(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define each(x,c) for(auto x: (c))
#define LB(x,a) lower_bound(all(x), a)
#define UB(x,a) upper_bound(all(x), a)
const ll mod=1e9+7;
const ll INF=1e18;
const double EPS=1.0e-10;
const ld PI=M_PI;

int main(){
    int N; cin>>N;
    vector<pair<ld,int>> arg;
    vector<ld> x(N),y(N);
    rep(i,N){
        cin>>x[i]>>y[i];
        arg.pb({atan2(y[i],x[i]),i});
        arg.pb({atan2(y[i],x[i])+2.0*PI,i});
    }
    sort(all(arg));
    vector<ld> Sx(2*N+1),Sy(2*N+1); Sx[0]=Sy[0]=0.0;
    rep(i,2*N){
        Sx[i+1]=Sx[i]+x[arg[i].nd];
        Sy[i+1]=Sy[i]+y[arg[i].nd];
    }
    ld ans=0.0;
    rep(i,N){
        FOR(j,i,i+N){
            ans=max(ans,(ld)sqrt((Sx[j+1]-Sx[i])*(Sx[j+1]-Sx[i])+(Sy[j+1]-Sy[i])*(Sy[j+1]-Sy[i])));
        }
    }
    printf("%.15Lf\n",ans);
    return 0;
}