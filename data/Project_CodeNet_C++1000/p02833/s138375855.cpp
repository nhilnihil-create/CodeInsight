//解説AC
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int main(){
    ll n;
    cin >> n;
    ll ans=0;
    ll a=10;
    ll b=0;
    if(n%2==1)
        cout << ans << endl;
    else{
        while(n>=a){
            b++;
            ans+=n/a;
            a*=5;
        }
        cout << ans << endl;
    }

	return 0;
}