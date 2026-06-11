#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=5003;
const ll INF=1LL<<30;

bool compare(pair<ll,ll> a,pair<ll,ll> b){
    return atan2(a.first,a.second)<atan2(b.first,b.second);
}

int main(){
    
    int N;cin>>N;
    vector<pair<ll,ll>> P(N);
    for(int i=0;i<N;i++){
        cin>>P[i].first>>P[i].second;
    }
    
    sort(all(P),compare);
    for(int i=0;i<N;i++){
        P.push_back(P[i]);
    }
    
    vector<ll> xsum(2*N+1,0.0),ysum(2*N+1,0.0);
    ll ans=0;
    
    for(int i=1;i<=2*N;i++){
        xsum[i]+=xsum[i-1]+P[i].first;
        ysum[i]+=ysum[i-1]+P[i].second;
    }
    
    for(int i=0;i<N;i++){
        for(int j=i;j<i+N;j++){
            ll X=xsum[j+1]-xsum[i];
            ll Y=ysum[j+1]-ysum[i];
            ans=max(ans,X*X+Y*Y);
        }
    }
    
    long double left=0.0,right=2000000000.0,mid;
    for(int i=0;i<300;i++){
        mid=(left+right)/2.0;
        if(mid*mid>=ans) right=mid;
        else left=mid;
    }
    
    cout<<setprecision(25)<<mid<<endl;
}



