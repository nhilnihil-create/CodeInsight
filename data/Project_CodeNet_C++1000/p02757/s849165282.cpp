#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    int n,p;
    string s;
    cin >> n >> p >> s;
    if(p==2 || p == 5){
        ll ans=0;
        reverse(s.begin(), s.end());
        rep(i,n){
            if((s[i]-'0')%p == 0) ans += (n-i);
        }
        cout << ans << endl;
        return 0;
    }else{
        ve<int> mod(p);
        reverse(s.begin(), s.end());
        int k = 1;
        int sum = 0;
        rep(i,n){
            sum += ((s[i]-'0')*k) % p;
            sum %= p;
            mod[sum]++;
            k *= 10;
            k %= p;
        }
        ll ans=0;
        mod[0]++;
        rep(i,p){
            ans += (ll)(mod[i]-1)*mod[i]/2;
        }
        cout << ans << endl;
        return 0;
    }
}