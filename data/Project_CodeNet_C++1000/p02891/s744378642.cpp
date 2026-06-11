#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    string s;
    ll k;
    cin>>s>>k;
    ll n=s.size(),cnt=1,ans=0;
    rep(i,n-1){
        if(s[i]==s[i+1]) cnt++;
        else break;
    }
    if(cnt==n){
        cout<<n*k/2;
        return 0;
    }
    rep(i,n-1){
        if(s[i]==s[i+1]){
            ans++;
            s[i+1]='.';
        }
    }
    ans*=k;
    if(s[0]==s[n-1]&&cnt%2==1) ans+=k-1;
    cout<<ans;
}