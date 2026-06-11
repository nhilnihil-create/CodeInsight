#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

ll N,K,C;
string S;
ll A[200010], B[200010];
int main(){
    cin>>N>>K>>C>>S;
    C++;
    ll count=1, i=0;
    while(true){
        if(i>=N) break;
        if(S[i]=='o'){
            A[i]=count;
            count++;
            i+=C;
        }
        else i++;
    }
    i=N-1; count=K;
    while(true){
        if(i<0) break;
        if(S[i]=='o'){
            B[i]=count;
            count--;
            i-=C;
        }
        else i--;
    }
    //rep(i,N) cout<<A[i]<<' '<<B[i]<<endl;
    rep(i,N) if(A[i]==B[i] && A[i]!=0) cout<<i+1<<endl;

}