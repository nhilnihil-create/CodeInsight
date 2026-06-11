#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
#define NUM 1000000010
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n;
    cin>>n;
    vector<int> x(n),y(n);
    rep(i,n) cin>>x[i]>>y[i];
    ld sum=0,dist;
    rep(i,n){
        repi(j,i+1,n){
            dist=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            sum+=sqrt(dist);
        }
    }
    cout<<fixed<<setprecision(8)<<sum*2/n;
}