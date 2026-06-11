#include<bits/stdc++.h>
#define ll long long 
#define P pair<ll ,ll>
using namespace std;

ll gcd(ll a,ll b){
    if(a<b)return gcd(b,a);
    if(a%b==0)return b;
    return gcd(b ,a%b);
}
int main(){
    int m,d;
    cin >> m >> d;
    int ans = 0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=d;j++){
            if(j%10 > 1 && j/10 > 1 && (j%10)*(j/10)==i) ans++;
        }    
    }

    cout << ans << endl;
}