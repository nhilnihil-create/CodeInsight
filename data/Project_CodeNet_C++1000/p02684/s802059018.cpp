#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        --a[i];
    }
    vector<ll> visited(n,-1);
    ll s=0,cnt=0;
    while (visited[s]==-1) {
        visited[s]=cnt;
        s=a[s];
        ++cnt;
    }
    if (k>=cnt) {
        ll c=cnt-visited[s];
        k=(k-visited[s])%c;
        rep(i,n) {
            if (visited[i]==visited[s]+k) {
                cout << i+1 << endl;
                break;
            }
        }
    } else {
        rep(i,n) {
            if (visited[i]==k) {
                cout << i+1 << endl;
                break;
            }
        } 
    }
    
    
    
    
    return 0;   
}