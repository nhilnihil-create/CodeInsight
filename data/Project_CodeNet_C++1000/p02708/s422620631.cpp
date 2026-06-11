#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<functional>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
typedef long long int ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<signed(n);i++)
#define EREP(i,n) for(int i=1;i<=signed(n);i++)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
//#define EVEL 1
#ifdef EVEL
#define DEB(X) cout << #X <<":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {}
#define TF(f) {}
#define END {}
#endif
const ll MOD = 1000000007;
const ll INF = 9e14;
typedef std::pair<ll,ll> P;
struct edge{ int to,cost; };
#define VMAX 100000

ll K,N,X,A[200010];
ll ans=0;
ll S[3][5000];
map< int64_t, int > ret;
int main(){
    cin>>N>>K;
    REP(i,N+1){
        A[i]=i;
    }REP(i,N+1){
        A[i+1]+=A[i];
    }
    REP(i,N+1){
        //DEB(i)DEB(A[i])DEB(N-1-i)DEB(A[N-1-i])END;
        if(i+1>=K){
            if(N-1-i>=0)ans=(ans+(A[N]-A[N-1-i]-A[i])+1)%MOD;
            else ans=(ans+(A[N]-A[i])+1)%MOD;
        }
    }
    cout<<ans<<endl;

}