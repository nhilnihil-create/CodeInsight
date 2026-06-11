#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
using namespace std;


ll arr[10000010];
int spf[10000010];

ll get(ll x){
    ll f = spf[x];
    if(spf[x] == x){
        arr[x] = 2;
        return 2;
    }
    ll temp = 0;
    ll kk = x;
    ll cnt = arr[x/f];
    x = x/f;
    while(x%f==0) x/=f , temp++;
    cnt = cnt/(temp+1);
    cnt = cnt*(temp+2);
    arr[kk] = cnt;
    return cnt;
}



void sol(){
    ll n; cin >> n;
    ll ans=1;
    for(ll i=2;i<=n;i++){
        ans += i*get(i);
     //   cout << get(i) << "\n";
    }
    cout << ans;
}

int main() {
    forr(i,10000010) spf[i] = i;
    for(int i=2;i<=10000000;i++){
        if(spf[i] == i){
            for(int j=2;j*i<=10000000;j++){
                if(spf[i*j] == i*j) spf[i*j] = i;
            }
        }
    }
    arr[1] = 1 , arr[2] = 2;
  //  for(int i=1;i<=20;i++) cout << spf[i] << " ";
    sol();
}
