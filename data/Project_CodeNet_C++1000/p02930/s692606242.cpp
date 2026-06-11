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
    vector<vector<int>> ans(n);
    int maxx=0;
    while((1<<maxx)<n)maxx++;
    rep(i,0,n-1){
        ans[i].resize(n-i);
        rep(j,i,n-1){
            int b=-1;
            rep(k,0,maxx)if(((i>>k)&1)!=(((j+1)>>k)&1))b=k;
            ans[i][j-i]=b;
        }
    }
    rep(i,0,n-1){
        rep(j,0,n-i-1)printf("%d ",ans[i][j]+1);
        printf("\n");
    }
    return 0;
}
