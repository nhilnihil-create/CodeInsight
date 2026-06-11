#include <bits/stdc++.h>
using namespace std;
int n,m,a[100001];
int gcd(int x,int y) {
    if (x<y) swap(x,y);
    if (y==0) return x;
    else return gcd(y,x%y);
}
int main() {
    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>a[i];
    long long lcm=0,p2=0;
    for (int i=0; i<n; i++) {
        long long num=a[i];
        long long cnt=0;
        while (num%2==0) {
            num/=2; cnt++;
        }
        if (i==0) {
            p2=cnt;
            lcm=num;
        }
        else if (cnt!=p2) {
            cout<<0<<'\n'; return 0;
        }
        else {
            lcm=(lcm*num/gcd(lcm,num));
        }
    }
    lcm=lcm*(long long)(pow(2LL,p2));
    long long ans=(2*m)/lcm;
    if (ans%2!=0) ans=ans/2+1;
    else ans/=2;
    cout<<ans<<'\n';
}