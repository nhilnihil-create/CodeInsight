#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
#define NUM 1000000000
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    long n,k,s;
    cin>>n>>k>>s;
    rep(i,k) cout<<s<<" ";
    repi(i,k,n){
        if(s<NUM) cout<<s+1<<" ";
        else cout<<1<<" ";
    }
}