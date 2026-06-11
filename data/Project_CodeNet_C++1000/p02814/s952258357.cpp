#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main() {
    ll n,m;cin>>n>>m;
    
    ll a[n];
    ll b[n];
    ll tmp;
    ll Num = 1;
    rep(i,n) {
        cin>>a[i];
        
        int cc = 0;
        tmp = a[i];
        while(tmp%2==0){
            ++cc;
            tmp/=2;
        }
        b[i]=cc;
        
        Num = Num/__gcd(Num,a[i])*a[i];
        if(Num > 2*m){
          cout<<0<<endl;
          return 0;
        }
    }
    
    sort(b,b+n);
    rep(i,n-1){
        if(b[i]!=b[n-1]){
          cout<<0<<endl;
          return 0;
        }
    }
    
    ll Num2 = Num/2;
    
    ll ans = m / Num2 - (m / Num);
    
    cout<<ans<<endl;
	return 0;
}