#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e18
#define PI 3.141592653589793238
typedef long long ll;
#define N 100010

int gcd(int a, int b){
    int r;
    r = a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main() {
    int k, ans=0;cin>>k;

    for(int a=1; a<=k; a++){
        for(int b=1; b<=k; b++){
            for(int c=1; c<=k; c++){
                ans += gcd(gcd(a,b),c);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}