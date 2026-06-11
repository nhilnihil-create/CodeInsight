#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int a[m],total=0;
    rep(i,m){
        cin>>a[i];
        total+=a[i];
    }
    if(total>n) cout<<"-1"<<endl;
    else cout<<n-total<<endl;
}