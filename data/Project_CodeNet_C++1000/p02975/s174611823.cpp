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
    int n;
    cin>>n;
    map<int,int> mp;
    int a;
    rep(i,n){
        cin>>a;
        mp[a]++;
    }
    int m=mp.size();
    bool ans=false;
    if(mp[0]==n) ans=true;
    else if(m==2&&mp[0]==n/3&&n%3==0) ans=true;
    else if(m==3&&n%3==0){
        bool flag=true;
        ll s=0;
        for(auto p:mp){
            if(p.second&&p.second!=n/3) flag=false;
            s^=p.first;
        }
        if(flag&&s==0) ans=true;
    }
    if(ans) cout<<"Yes";
    else cout<<"No";
}