#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll W,H,x,y;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>W>>H>>x>>y;
long double ans=W*H/2.0;
ll type=0;
W==2*x&&H==2*y?type=1:type=0;
cout<<fixed<<setprecision(20)<<ans<<" "<<type<<endl;

}
	