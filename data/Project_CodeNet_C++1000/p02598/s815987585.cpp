#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007

int main(){
    int n,k;
    cin >> n >> k;
    vll a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    ll ng=0,ok=1e10,mid;
    ll cnt;
    while(abs(ok-ng)>1){
        mid=(ok+ng)/2;
        cnt=0;
        for(int i=0;i<n;i++){
            cnt+=(a[i]+mid-1)/mid;
            cnt--;
        }
        if(cnt<=k) ok=mid;
        else ng=mid;
    }
    cout << ok  << endl;

    return 0;
}