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
const double PI=M_PI;

int main(){
    int N; cin>>N;
    priority_queue<ll, vec, greater<ll>> plus;
    PQ minus;
    rep(i,N){
        ll A; scanf("%lld",&A);
        if(A>=0) plus.push(A);
        else     minus.push(A);
    }
    if(minus.empty()){
        ll p=plus.top(); plus.pop();
        minus.push(p);
    }
    if(plus.empty()){
        ll m=minus.top(); minus.pop();
        plus.push(m);
    }
    vector<P> v;
    rep(i,N-1){
        ll p=plus.top(); plus.pop();
        ll m=minus.top(); minus.pop();
        if(SZ(plus) > SZ(minus)){
            v.pb({m,p});
            minus.push(m-p);
        }
        else{
            v.pb({p,m});
            plus.push(p-m);
        }
    }
    cout<<plus.top()<<endl;
    rep(i,N-1){
        cout<<v[i].st<<" "<<v[i].nd<<endl;
    }
    return 0;
}