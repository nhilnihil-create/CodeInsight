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
    int n,m;
    cin>>n>>m;
    vector<int> a(n),cnt(n);
    int s,c;
    bool flag=true;
    rep(i,m){
        cin>>s>>c;
        if(cnt[s-1]!=0&&c!=a[s-1]) flag=false;
        a[s-1]=c;
        cnt[s-1]++;
    }
    if(cnt[0]!=0&&a[0]==0&&n!=1) flag=false;
    if(flag){
        if(a[0]==0&&n!=1) a[0]=1;
        rep(i,n) cout<<a[i];
    }
    else cout<<-1;
}