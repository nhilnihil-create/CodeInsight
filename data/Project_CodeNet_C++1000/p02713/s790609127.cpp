#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define rep(i,n) for(int i=1;i<=(int)(n);i++)
#define ll long long
#define BIT_FLAG_0 (1<<0) // 0000 0000 0000 0001
int gcd(int a, int b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

int main(){
    int k;
    cin >> k;
    ll ans=0;
    rep(i,k){
        rep(j,k){
            rep(l,k){
                ans+=gcd(gcd(i,j),l);
            }
        }
    }  
    cout << ans << endl;  
}