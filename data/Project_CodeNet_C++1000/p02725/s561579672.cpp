#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e18
#define PI 3.141592653589793238
typedef long long ll;
#define N 200010

int main() {
    ll k,n,a[N],b[N],ans=0;cin>>k>>n;
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<n-1; i++) b[i] = (a[i+1]-a[i]);
    b[n-1] = a[0]+k-a[n-1];
    sort(b, b+n);
    for(int i=0; i<n-1; i++) ans += b[i];
    cout<<ans<<endl;


    return 0;
}