#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll N=pow(10,9)+7;

ll mod_pow(ll x, ll y){
    ll ans;
    if(y==0) return 1;
    else if(y%2==0){
        ans = (mod_pow(x,y/2) * mod_pow(x,y/2)) % N;
        return ans;
    }
    else{
        ans = (mod_pow(x,y/2) * mod_pow(x,y/2)) % N;
        ans = (ans*x)%N;
        return ans;
    }
}

ll combi(ll n, ll m){
    ll up=1;
    ll down=1;
    ll ans;
    for(int i=0; i<m; i++){
        up = (up*(n-i))%N;
        down = (down*(i+1))%N;
    }
    ans = (up*mod_pow(down, N-2)) % N;
    return ans;
}


int main(){
    ll x,y;
    cin >> x >> y;
    if(2*x-y<0 || (2*x-y)%3!=0){
        cout << 0 << endl;
        return 0;
    }
    if(2*y-x<0 || (2*y-x)%3!=0){
        cout << 0 << endl;
        return 0;
    }
    ll p=(2*x-y)/3;
    ll q=(2*y-x)/3;
    cout << combi(p+q, p) << endl;
}
