#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
    int n;
    cin >> n;
    map<ll,ll> mp1,mp2;
    rep(i,n){
        ll a;
        cin >> a;
        mp1[a+i+1]++;
        if(i+1-a>0) mp2[i+1-a]++;
    }
    ll ans=0;
    for(auto i : mp1){
            ans += i.second*mp2[i.first];
    }
    cout << ans << endl;
}