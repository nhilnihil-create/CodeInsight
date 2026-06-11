#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    int n,p; cin>>n>>p;
    string s; cin>>s;
    ll ans = 0;
    if(p==2||p==5){
        rep(i,n){
            if((s[i]-'0')%p==0) ans+=i+1;
        }
        cout << ans << endl;
        return 0;
    }

    vector<int> sum(n+1);
    int ten = 1;
    for(int i=n-1;i>=0;i--){
        int a = (s[i]-'0')*ten%p;
        sum[i] = (sum[i+1]+a)%p;
        ten *= 10; ten %= p;
    }
    vector<int> cnt(p);
    for(int i=n;i>=0;i--){
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    cout << ans << endl;
}