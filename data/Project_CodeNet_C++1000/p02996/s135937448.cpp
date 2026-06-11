
#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
ll LCM(int a, int b){
    return a*b/gcd(a,b);
}

int main(void){
    int n;
    cin>>n;
    vector<pair<ll,ll>> p(n);
    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        p[i]=make_pair(b,a);
    }
    sort(p.begin(),p.end());
    bool ok=true;
    ll time=0;
    rep(i,0,n){
        if(time+p[i].second<=p[i].first){
            time+=p[i].second;
        }else {ok=false; break;}
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;

}