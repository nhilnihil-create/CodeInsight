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
    int n,k,r,s,p;
    string t;
    cin>>n>>k>>r>>s>>p>>t;
    int ans=0;
    rep(i,n){
        if(i>=k&&t[i]==t[i-k]){
            t[i]='a';
            continue;
        }
        if(t[i]=='r') ans+=p;
        else if(t[i]=='s') ans+=r;
        else if(t[i]=='p') ans+=s;
    }
    cout<<ans;
}