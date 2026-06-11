#include<bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

#define ll long long int
#define loop(i, n) for (int i = 0; i < n; i++)
#define loops(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define MOD 1000000007

int modexp(int a,int n,int mod){
    if(n == 0){
        return 1;
    }
    ll res = modexp(a*a%mod,n/2,mod);
    if(n&1){
        res=(res*a)%mod;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    ll ans = 0;
    if(p == 2 || p == 5){
        for(int i = 0; i<n; i++){
            if((s[i]- '0')%p == 0){
                ans+=(i+1);
            }
        }
        cout<<ans<<"\n";
    }
    else{
    ll cnt[p];
    memset(cnt,0,sizeof(cnt));
    cnt[0] = 1;
    int cur = 0;
    for(int i = 0; i<n; i++){
        cur*=10;
        cur+= (s[i] - '0');
        cur%=p;
        int val = modexp(10,n-i-1,p)*cur;
        val = val%p;
        cnt[val]++;
    }
    
    for(int i = 0; i<p; i++){
        ans += (cnt[i]*(cnt[i]-1))/2;
    }
    cout<<ans<<"\n";
    }
}