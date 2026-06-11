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
    vector<ll> h(n);
    rep(i,n) cin>>h[i];
    for(int i=n-2;i>=0;i--){
        if(h[i]<=h[i+1]) continue;
        else if(h[i]-1==h[i+1]) h[i]--;
        else{
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}