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
    vector<int> b(n),a(n);
    b[0]=100010;
    repi(i,1,n){
        cin>>b[i];
        a[i-1]=min(b[i],b[i-1]);
    }
    a[n-1]=b[n-1];
    ll sum=0;
    rep(i,n) sum+=a[i];
    cout<<sum;
}