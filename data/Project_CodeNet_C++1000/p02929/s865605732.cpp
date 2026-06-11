#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
set<string> c;
const ll mod=1000000007;
const ll mod2=998244353;
const ll inf=100000000000000000;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
map<ll,ll> mp;
ll df(ll n){
    ll res=1;
    while(--n){
        res*=(n+1);
        res%=mod;
    }
    return res;
}
int main(){
ll n;
cin>>n;
string s;
cin>>s;
string tmp="L";
for(int i=1;i<s.size();i++){
    if(s.at(i-1)!=s.at(i)){
        tmp+=tmp.at(tmp.size()-1);
    }
    else {
        if(tmp.at(tmp.size()-1)=='L')tmp+='R';
        else tmp+='L';
    }
}
int cntl=0,cntr=0;
for(int i=0;i<tmp.size();i++){
    if(tmp.at(i)=='L')cntl++;
    else cntr++;
}
if(cntr!=cntl||s.at(0)=='W'||s.at(s.size()-1)=='W'){
    cout<<0<<endl;
    return 0;
}
cntl=0;cntr=0;
ll ans=1;
for(int i=0;i<tmp.size();i++){
    if(tmp.at(i)=='L')cntl++;
    else{
             ans*=cntl;
             ans%=mod;
             cntl--;
    }
}
ans=ans*df(n)%mod;
cout<<ans<<endl;
}


