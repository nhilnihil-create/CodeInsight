#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ff first
#define ss second
#define lp(a,n) for(ll i=a; i<n; i++)
#define lpi(a,n) for(int i=a; i<n; i++)
#define w(t) int t; cin>>t; while(t--)
#define vi vector<int> 
#define vll vector<ll>
#define inf 1e9
#define mod 1e9 + 7
using namespace std;
ll gcd(ll a,ll b){
    if(a==0)return b;
    return gcd(b%a,a);
}
ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}
ll power(ll x, ll y) 
{ 
    ll res = 1;     
    while (y > 0) 
    { 
        if (y & 1) 
            res = res*x; 
   
        y = y>>1;
        x = x*x;  
    } 
    return res; 
}

int main(){
    int n, p;
    cin>>n>>p;
    string s;
    cin>>s;
    ll ans=0;
    if(p==2){
        lpi(0,n){
            if((s[i]-'0')%2 == 0){
                ans += i+1;
            }
        }
    }
    else if(p==5){
        lpi(0,n){
            if((s[i]-'0')%5==0) ans+=i+1;
        }
    }
    else{
        map<int , int> mp;
        int t=0, p1=1;
        mp[0]++;
        for(int i=n-1; i>=0; i--){
            t = (t+(s[i]-'0')*p1)%p;
            p1 = (p1*10)%p;
            ans += mp[t];
            mp[t]++;
        }
    }
    cout<<ans;
}