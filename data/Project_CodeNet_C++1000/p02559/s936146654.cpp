//#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"
#include "atcoder/fenwicktree.hpp"
using namespace std;
using namespace atcoder;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,q; cin>>n>>q;
    fenwick_tree<ll> bit{n};
    rep(i,n){
        int a; cin>>a;
        bit.add(i,a);
    }
    rep(_,q){
        int t,l,r; cin>>t>>l>>r;
        if(t==0){
            bit.add(l,r);
        }
        else{
            printf("%lld\n",bit.sum(l,r));
        }
    }
}
