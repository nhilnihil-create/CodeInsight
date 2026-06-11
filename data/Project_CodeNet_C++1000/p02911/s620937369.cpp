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
    ll k,saidai=0;
    int n,q,x;
    cin>>n>>k>>q;
    vector<ll> a(n);
    rep(i,n) a[i]=k-q;
    rep(i,q){
        cin>>x;
        a[x-1]++;
    }
    rep(i,n){
        if(a[i]>0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}