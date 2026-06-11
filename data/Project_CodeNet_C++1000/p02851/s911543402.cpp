#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll,ll>
#define PP pair<P,P>
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    vector<ll> s(n+1);
    s[0]=0;
    rep(i,n){
        int a; cin >> a;
        s[i+1]=s[i]+a;
    }
    map<int,int> num;
    ll ans=0;
    rep(i,n+1){
        if(i>=k) num[(s[i-k]-(i-k))%k]--;
        ans+=num[(s[i]-i)%k];
        num[(s[i]-i)%k]++;
        //cout << ans << endl;
    }

    cout << ans << endl;
return 0;
}
