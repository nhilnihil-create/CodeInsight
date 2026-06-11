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
    ll n,k;cin>>n>>k;
    //ll ans=INF, tmp=INF;
    n=n%k;
    while(n>(k/2)){
        n = abs(k-n);
    }
    cout<<n<<endl;
    

    return 0;
}