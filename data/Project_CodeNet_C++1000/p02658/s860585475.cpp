#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;
ll M=1000000000000000000;
ll a[100010];
int main(void){
    ll n,ans=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
            cout<<0<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if(ans>M/a[i]){
            cout<<-1<<endl;
            return 0;
        }
        else ans*=a[i];
    }
    cout<<ans<<endl;
}