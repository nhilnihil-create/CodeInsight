#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N; cin>>N;
    int v[N];
    rep(i,N)cin>>v[i];
    sort(v,v+N);
    double ans=0.0;
    rep(i,N-2){
        ans+=v[N-1-i]/pow(2.0,i+1);
    }
    ans+=(v[0]+v[1])/pow(2.0,N-1);
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}