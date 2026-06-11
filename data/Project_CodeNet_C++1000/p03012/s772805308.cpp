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
    vector<int> w(n);
    int all=0,minus=0;
    rep(i,n){
        cin>>w[i];
        all+=w[i];
    }
    int minw=all;
    rep(i,n){
        minus+=w[i];
        minw=min(minw,abs((all-minus)-minus));
    }
    cout<<minw;
}