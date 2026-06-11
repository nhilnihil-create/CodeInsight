#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define forN(i, n) for(int i = 0; i <n ; ++i)
#define endl "\n"
typedef long long ll;
using namespace  std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int N = 2e5 +5 ;
int n , k;

int main () {
    fastIO
    cin>>n>>k;
    ll ans  =0;
    while(n>0){
        n/=k;
        ans++;
    }
    cout<<ans;
}
