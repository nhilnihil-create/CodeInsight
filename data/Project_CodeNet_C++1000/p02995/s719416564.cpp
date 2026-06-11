#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

ll gcd(ll a,ll b){
    if (a%b == 0){
       return(b);
   }else{
       return(gcd(b,a%b));
   }
}

ll lcm(ll a,ll b){
   return a*b / gcd(a,b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll ans=b-a+1;
    ans-=((b/c)-(a/c));
    if(a%c==0) --ans;
    ans-=((b/d)-(a/d));
    if(a%d==0) --ans;
    ll x=lcm(c,d);
    ans+=((b/x)-(a/x));
    if(a%x==0 && a>=x) ++ans;
    cout << ans << "\n";
    return 0;
}   