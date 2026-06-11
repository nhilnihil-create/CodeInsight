#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
#define NUM 1000000007
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ll i,n,k;
    cin>>n>>k;
    ll sum=0,cnt=0,MIN,MAX;
    for(i=k;i<=n+1;i++){
        MIN=i*(i-1)/2;
        MAX=i*(2*n-(i-1))/2;
        cnt=(MAX-MIN)+1;
        sum=(sum+cnt)%NUM;
    }
    cout<<sum<<endl;
}