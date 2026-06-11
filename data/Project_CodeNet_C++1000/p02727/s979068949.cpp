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

int main(){
    ll X,Y,A,B,C;
    cin>>X>>Y>>A>>B>>C;
    vector<ll> r(A),b(B),g(C),s(X+Y);
    for(int i=0;i<A;i++) cin>>r[i];
    for(int i=0;i<B;i++) cin>>b[i];
    for(int i=0;i<C;i++) cin>>g[i];
    sort(r.begin(),r.end(),greater<ll>());
    sort(b.begin(),b.end(),greater<ll>());
    sort(g.begin(),g.end(),greater<ll>());
    ll ans=0;
    for(int i=0;i<X;i++){
      ans+=r[i];
      s[i]=r[i];
    }
    for(int i=0;i<Y;i++){
      ans+=b[i];
      s[X+i]=b[i];
    }
    sort(s.begin(),s.end());
    for(int i=0;i<C;i++){
        if(g[i]<=s[i]||i>=X+Y) break;
        ans+=g[i]-s[i];
    }
    cout<<ans<<endl;
    return 0;
}