#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(y==0)return x;
    return gcd(y,x%y);
}
ll LCM(ll a, ll b){
    return a/gcd(a,b)*b;
}

int main(void)
{
    ll a,v,b,w,t;
    cin>>a>>v>>b>>w>>t;
    cout<<(abs(a-b)-(v-w)*t<=0?"YES":"NO")<<endl;
    return 0;
}