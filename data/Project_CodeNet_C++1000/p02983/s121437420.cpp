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
    ll l,r;
    cin>>l>>r;
    if(r-l>=2019) cout<<0;
    else{
        int mini=2020*2020;
        repi(i,l,r){
            repi(j,i+1,r+1) mini=min(mini,((i%2019)*(j%2019))%2019);
        }
        cout<<mini;
    }
}