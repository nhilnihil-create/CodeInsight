#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)
#define INF (1LL << 60)
#define itn int

int main(void){
    ll l,r;
    cin >> l >> r;
    
    bool check = false;
    for(ll i = 2019;i <= r;i += 2019){
        if(l <= i && i <= r)check = true;
    }
    
    if(l == 0 || check){
        cout << 0 << endl;
    } else {
        ll alina = 2019;
        for(ll i = l;i <= r;i++){
            for(ll j = i+1;j <= r;j++){
                ll num = i % 2019,num2 = j % 2019;
                alina = min(alina,(num*num2)%2019);
            }
        }
        cout << alina << endl;
    }
}
