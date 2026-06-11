#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;n>i;++i)
#define MOD 1000000007
using namespace std;
using ll=int64_t;
using pii=pair<int,int>;
using vi=vector<int>;
using VI=vector<ll>;
using vis=vector<string>;
using vvi=vector<vi>;
//最大公約数
int gcd(int a,int b){
    if(a%b==0)
    return b;
    return gcd(b,a%b);
}
//最小公倍数
int lcm(int a,int b){
   return a*b/gcd(a,b);
}
bool prime(int num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
        if (num % i == 0)
        return false;
    }
    return true;
}
int main(){
    ll n; cin>>n;
    VI d(n);
    rep(i,n) cin>>d[i];
    sort(d.begin(),d.end());
    ll b=d.size()/2;
    if(d[b-1]==d[b]){
        cout<<"0"<<endl;
        return 0;
    }
    cout<<d[b]-d[b-1]<<endl;
}