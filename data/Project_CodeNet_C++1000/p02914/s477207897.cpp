#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}
const int inf = INT_MAX / 2; const ll INF = LLONG_MAX / 2;
//template end



int main(){
    int n; scanf("%d",&n);
    vector<ll> a(n);
    rep(i,0,n)scanf("%lld",&a[i]);
    ll s=0;
    rep(i,0,n)s^=a[i];
    ll ans=s;
    rep(i,0,n)a[i]&=(~s);
    ll basis[61]={};
    rep(i,0,n){
        rrep(j,60,-1){
            if(a[i]>>j&1){
                if(!basis[j]){
                    basis[j]=a[i]; break;
                }
                else a[i]^=basis[j];
            }
        }
    }
    ll add=0;
    rrep(i,60,-1)chmax(add,add^basis[i]);
    ans+=2LL*add;
    printf("%lld\n",ans);
    return 0;
}