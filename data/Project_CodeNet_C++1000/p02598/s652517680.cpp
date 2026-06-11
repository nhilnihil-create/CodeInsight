#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector> 
#include<limits>
#include<numeric>
#include<type_traits>
#include<math.h>
#include<fstream>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7; 

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define out(str) cout << str << endl
#define ALL(a) (a).begin(),(a).end()
#define INF_INT (1<<30)
#define INF_LL (1ll<<62)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll N,K,L=1,R;
ll A[200200];

ll canCut(ll length){
    // cout<<"length: "<<length<<endl;
    ll ans=0;
    rep(i,N){
        ans+=(A[i]+length-1)/length-1;
    }
    // cout<<"ans: "<<ans<<endl;
    return ans;
}

int main(){
    cin>>N>>K;
    rep(i,N){
        cin>>A[i];
        R=max(R,A[i]);
    }
    ll mid;
    do{
        mid=(L+R)/2;
        if(canCut(mid)>K){
            L=mid;
        } else {
            R=mid;
        }
    }while(L+1<R);
    if(canCut(L)<=K)out(L);
    else out(R);
}