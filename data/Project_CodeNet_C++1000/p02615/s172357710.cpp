#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n;
    cin>>n;
    vector<ll>v(n);
    rep(i, n){
        cin>>v[i];
    }
    sort(v.begin(), v.end(), greater<ll>());
    int now = 0;
    ll ans = 0;
    rep(i, n-1){
        ans += v[now];
        if(i == 0) now++;
        else if(i%2 == 0) now++;
    }
    cout<<ans<<endl;
    return 0;
}