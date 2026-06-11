#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(ll i=(j);i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define NG cout <<"UNRESTORABLE" << endl;
#define INF 10101010

ll gcd(ll x,ll y){
    if (x%y == 0){
        return(y);
    }
    else{
        return(gcd(y, x%y));
    }
}
ld lcm(ll x, ll y) {
    return x / gcd(x, y) * y;//先に割り算をして掛けられる数を小さくして掛け算を行う
}
int main()
{
    ld A,B,C,D;
    cin >> A >> B >> C >> D;
    ld a_c=A/C;
    ld b_c=B/C;
    ld a_d=A/D;
    ld b_d=B/D;
    ll c_val=(ll)b_c-(ll)a_c;
    ld a_c_i=(ll)a_c;
    //cout << a_c-a_c_i << endl;
    if(ld(a_c-(ll)a_c)==0){
        c_val++;
    }
    
    ll d_val=(ll)b_d-(ll)a_d;
    if((ld)a_d-(ll)a_d==0){
        d_val++;
    }
    //cout << d_val << endl;
    ll ans=labs((ll)c_val+(ll)d_val);
    ld lcm_cd;
    if(C>D)
        lcm_cd=lcm(C,D);
    else{
        lcm_cd=lcm(D,C);
    }
    ld a_lcm=A/lcm_cd;
    ld b_lcm=B/lcm_cd;
    ll lcm_cd_val=(ll)b_lcm-(ll)a_lcm;
    //cout << lcm_cd_val << endl;
    if(a_lcm-(ll)a_lcm==0){
        lcm_cd_val++;
    }
    ans-=lcm_cd_val;

    ans=B-A+1-ans;
    cout << ans << endl;
}