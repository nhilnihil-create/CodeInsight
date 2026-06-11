#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
typedef long long ll;

int main() {
    ll n;cin>>n;
    ll a[n];
    int flag=0;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    for(int i=0; i<n-1; i++){
        if(a[i]==a[i+1]) flag=1;
    }
    if(flag==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}