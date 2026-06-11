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
    ld w,h,x,y;
    cin>>w>>h>>x>>y;
    if(w==2*x&&h==2*y){
        cout<<fixed<<setprecision(10)<<(w*h)/2<<" "<<1;
    }
    else cout<<fixed<<setprecision(10)<<(w*h)/2<<" "<<0;
}