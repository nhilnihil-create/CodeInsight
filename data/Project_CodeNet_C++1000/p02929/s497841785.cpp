#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
const long long INF = 1LL << 60;
const int MOD = 1000000007;
long long kaijo(long long x){
    ll p=1;
    while(x!=0){
        p*= x;
        p%=MOD;
        x--;
    }
    return p;
}
signed main(void){
    int n; cin>>n;
    int s[2*n];
    rep(i,2*n) {char a; cin>>a; if(a == 'W') s[i]=0; else s[i]=1;}
    int c[2*n+1];
    vector <int> res(2*n); 
    int a=0;
    c[0]=0;
    rep(i,2*n) { if((a+s[i])%2 && a>=0) {a++; res[i] = 1;} else {a--; res[i] = 0;} }
    int ans = 0;
    int cnt = 0;
    ans = 1;
    
    if(count(res.begin(), res.end(),1) != count(res.begin(), res.end(),0)) {cout<<0<<endl; return 0;}
    bool b=false;
    rep(i,2*n){
        if(res[i]) b=true;  
        if(!res[i]&&cnt!=0) ans *= cnt;
        if(b) cnt+=res[i] ? 1: -1;
        ans%=MOD;
    }
    cout<<(ans*kaijo(n))%MOD<<endl;
}
