#include <bits/stdc++.h>
#include<string>
#define mod 1000000007
using ll = long long;
using namespace std; 

int gcd(int a,int b){
    if (a%b==0) return b;
    return gcd(b,a%b);
}

int main(){
    int k; cin >> k;
    ll ans=0;
    for (int i=1;i<=k;i++){
        for (int j=1;j<=k;j++){
            for (int l=1;l<=k;l++){
                ans+=gcd(i,gcd(j,l));
            }
        }
    }
    cout << ans << "\n";
}

