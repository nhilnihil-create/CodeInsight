#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<l_l> vpl;
typedef vector<string> vs;
typedef pair<l_l,ll> lll;
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=1;i<=(n);i++)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=10100100100100100;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
template<class T> inline bool chmin(T& a,T b){
if(a>b){
a=b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a,T b){
if(a<b){
a=b;
return true;
}
return false;
}
int main(){
    ll n;cin>>n;
    set<ll> g1={2,4,5,7,9};
    set<ll> g2={0,1,6,8};
    set<ll> g3={3};
    if(g1.count(n%10)){
        cout<<"hon"<<endl;
    }else if(g2.count(n%10)){
        cout<<"pon"<<endl;
    }else cout<<"bon"<<endl;
    return 0;
}