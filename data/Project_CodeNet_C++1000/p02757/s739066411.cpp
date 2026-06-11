#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n,p;
    cin >> n >> p;
    string s;
    cin >> s;

    ll ans = 0;
    if(10 % p == 0){
        for(int i=0;i<n;i++){
            if((s[i]-'0')%p==0) ans += i+1; 
        }
    }else{
        vector<int> d(n+1,0);
        int ten = 1;
        for(int i=n-1;i>=0;i--){
            int tmp = (s[i]-'0')*ten % p;
            d[i] = (d[i+1]+tmp)%p;
            ten *= 10; ten %= p;
        }

        map<int,ll> mp;
        for(int i=0;i<=n;i++) mp[d[i]]++;
        for(auto p: mp){
            ll k = p.second;
            k *= k-1; k /= 2;
            ans += k;
            //cout << "mod:" << p.first << ", num:" << p.second << endl;
        }
    }

    cout << ans << endl;
}