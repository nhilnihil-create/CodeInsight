#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF=1e9;
const ll MOD=1e9+7;

ll gcd(ll x,ll y){
    if(y==0) return 0;
    return gcd(y,x%y);
}

int dis2(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
    int A,B,M;cin>>A>>B>>M;
    int a[A],b[B];
    for(int i=0;i<A;i++) cin>>a[i];
    for(int i=0;i<B;i++) cin>>b[i];
    int x[M],y[M],c[M];
    for(int i=0;i<M;i++){
        cin>>x[i]>>y[i]>>c[i];
    }
    int ans=*min_element(a,a+A)+*min_element(b,b+B);
    for(int i=0;i<M;i++){
        ans=min(ans,a[x[i]-1]+b[y[i]-1]-c[i]);
    }
    cout<<ans<<endl;
    return 0;
}