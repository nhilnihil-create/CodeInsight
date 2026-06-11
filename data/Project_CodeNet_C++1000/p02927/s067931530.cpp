#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
#define mod 1000000007

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;} 
ll lcm(ll x,ll y) {return x/gcd(x,y)*y;}

int main(){
    int m,d,ans=0;
    cin >> m >> d;
    for(int i=1;i<=m;i++){
        for(int j=20;j<=d;j++){
            if(j%10==1) continue;
            int now=j;
            int cnt=1;
            rep(i,2){
                cnt*=now%10;
                now/=10;
            }
            if(cnt==i) ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}



