#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ll long long

int main(){
    ll a;
    double b;
    cin >> a >> b;
    ll mid=b*100+0.5;
    ll ans;
    ans=mid*a/100;
    cout << ans << endl;
}