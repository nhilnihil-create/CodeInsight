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
    int n,d;
    cin>>n>>d;
    double x[n][d];
    rep(i,n){
        rep(j,d){
            cin>>x[i][j];
        }
    }
    int cnt=0;
    rep(i,n){
        repi(k,i+1,n){
            double sum=0;
            rep(j,d){
                double diff=abs(x[i][j]-x[k][j]);
                sum+=diff*diff;
            }
            bool flag=false;
            rep(j,sum+1) if(j*j==sum) flag=true;
            if(flag) cnt++;
        }
    }
    cout<<cnt;
}