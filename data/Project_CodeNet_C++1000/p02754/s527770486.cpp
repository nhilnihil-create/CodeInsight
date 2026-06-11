#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e18
#define PI 3.141592653589793238
typedef long long ll;

int main() {
    ll n,a,b; cin>>n>>a>>b;
    if(n%(a+b)==0) cout<<(n/(a+b))*a<<endl;
    else if(a<=n%(a+b)) cout<<(n/(a+b))*a + a<<endl;
    else cout<<(n/(a+b))*a + n%(a+b)<<endl;


    return 0;
}