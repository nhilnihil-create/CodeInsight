using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
// #define int long long
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define divup(a,b) ( ( (a) + ( (b) - 1u) ) / (b) ) // a/b の余り切り上げ
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
ll mod = 1000000007;
ll mod9 = 1000000009;

ll mem_sec[2][3];
ll sum_n[2];
signed main(){
    string s;
    cin>>s;
    ll sz = s.size();
    vector<vector<ll>> mem_n(2); 
    ll ct = 0;
    string sec_s;
    while(sz>0){
        rep(i,min(3LL,sz)){
            sec_s = s.substr(sz-1-i,1);
            if(sec_s =="?"){
                sec_s = "0";
                mem_sec[ct%2][i]++;
            }
            sum_n[ct%2] += stoi(sec_s)*pow(10,i);
        }
        ct++;
        sz -=3;
        if(sz>0) s = s.substr(0,sz);
    }
    ll smod = (sum_n[0]-sum_n[1])%13;
    while(smod<0) smod +=13;
    // cout<<smod<<"\n";
    ll t_mem[2][13];
    rep(i,2) rep(j,13) t_mem[i][j]=0;
    ll bai[2][3] = {{1,10,100},{-1,-10,-100}};
    bool f=0;
    ll tmod;
    rep(g,2) rep(h,3){
        rep(i,mem_sec[g][h]){
            if(f==0){
                rep(j,10){
                    tmod = (j*bai[g][h]+1300)%13; 
                    t_mem[0][tmod]=1;
                }
                f=1;
            }else{
                rep(j,13){
                    t_mem[1][j]=t_mem[0][j];
                    t_mem[0][j]=0;
                }
                rep(j,13){
                    rep(k,10){
                        tmod = (j+k*bai[g][h]+1300)%13; 
                        t_mem[0][tmod] += t_mem[1][j];
                        t_mem[0][tmod] %= mod;
                    }
                }
            }
        }
    }
    ll ttt = 5-smod;
    if(ttt<0) ttt+=13;
    if(f==0) {
        cout<<(smod%13==5)<<"\n";
    }else cout<<t_mem[0][ttt]<<"\n";
    // rep(i,13) cout<<t_mem[0][i]<<endl;
}
