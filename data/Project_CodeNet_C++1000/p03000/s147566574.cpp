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
    int n,x;
    cin>>n>>x;
    vector<int> l(n);
    rep(i,n) cin>>l[i];
    int d=0,cnt=1;
    rep(i,n){
        if(d+l[i]<=x) cnt++;
        d+=l[i];
    }
    cout<<cnt;
}