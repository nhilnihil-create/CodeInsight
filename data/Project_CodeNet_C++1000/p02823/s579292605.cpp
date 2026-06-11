#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;

int main(){
    ll n,a,b; cin>>n>>a>>b;
    if((b-a)%2==0){
        cout<<(b-a)/2<<endl;
    }else {
        if((a-1)>=(n-b)){
            cout<<-(a-b+1)/2 +n-b+1<<endl;
        }else {
            cout<<(b-a-1)/2 +a<<endl;
        }
    }
}