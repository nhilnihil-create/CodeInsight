#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long modpow(long long n, long long k, long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}
int main(){
string s;
cin >> s;
int n = s.size();
vector<ll>remain(n+1);
for(int i = 1;i<=n;i++){
    remain[i] = (remain[i-1]+modpow(10,i-1,2019)*(s[n-i]-'0'))%2019;
}
map<ll,ll>mp;
for(int i = 0;i<=n;i++) mp[remain[i]]++;
ll ans = 0;
for(auto it = mp.begin();it!=mp.end();it++){
    ans += (it->second-1)*it->second/2;
}
cout << ans;
return 0;
}