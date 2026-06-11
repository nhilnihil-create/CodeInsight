#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 200000;
ll mod = INF;

ll a[maxn];
ll n;

int main(){
    cin >> n;
    rep(i,n)cin >> a[i];
    sort(a,a+n);
    rep(i,n-1){
        if(a[i]==a[i+1]){
            cout << "NO"<<endl;
            return 0;
        }
        if(i==n-2){
            cout << "YES"<<endl;
        }
    }    
    return 0;
}