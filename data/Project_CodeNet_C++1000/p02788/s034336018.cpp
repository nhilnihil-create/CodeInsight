#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const int INF=2e9;

ll N,D,A;
vector<ll> X,H;

ll solve(){
    vector<int> isd(N);
    for(int i=0;i<N;++i) isd[i]=i;
    sort(isd.begin(),isd.end(),[&](int i,int j){
        return X[i]<X[j];
    });
    vector<ll> nX(N),nH(N);
    for(int i=0;i<N;++i){
        nX[i]=X[isd[i]];nH[i]=H[isd[i]];
    }
    X=nX;H=nH;
    vector<ll> S(N+1,0);
    ll res=0;
    for(int i=0;i<N;++i){
        if(S[i]<H[i]){
            ll need=(H[i]-S[i]+A-1)/A;
            ll right=upper_bound(X.begin(),X.end(),X[i]+2*D)-X.begin();
            S[i]+=need*A;
            S[right]-=need*A;
            res+=need;
        }
        S[i+1]+=S[i];
    }
    return res;
}

int main(){
    cin>>N>>D>>A;
    X.resize(N);H.resize(N);
    for(int i=0;i<N;++i) cin>>X[i]>>H[i];
    cout<<solve()<<endl;
    return 0; 
}