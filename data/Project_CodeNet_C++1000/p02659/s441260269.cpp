#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    ll a;
    string b;
    cin>>a>>b;
    ll B=100*(b[0]-'0')+10*(b[2]-'0')+b[3]-'0';
    ll ans=a*B;
    ans/=100;

    cout<<ans<<endl;
}
