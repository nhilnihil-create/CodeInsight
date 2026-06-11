#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    bool ok = 1;
    int H = in(),W = in(),A = in(),B = in();
    if(W - A < A)ok = 0;
    if(H - B < B)ok = 0;
    string one = "",two = "";
    REP(i,W){
        if(i < A){
            one += '1';
            two += '0';
        }else{
            one += '0';
            two += '1';
        }
    }
    REP(i,H){
        if(i < B){
            cout << one << "\n";
        }else{
            cout << two << "\n";
        }
    }
}