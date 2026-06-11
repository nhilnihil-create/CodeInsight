#include<iostream>
#include <string>
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define endl "\n"
#define sz(v) (int)(v.size())
#define len(s) (int)(s.length())
#define M 1000000007
#define all(v) v.begin(),v.end()
#define fr(a,b,c) for(ll i=a;i<=b;i+=c)
#define inarr(arr,n); for(ll i=0;i<n;i++) cin >> arr[i];
#define outarr(arr,n); for(ll i=0;i<n;i++) cout<<arr[i]<<" ";
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll inf = 9e18;
const ld pi = 2*acos(0.0); 
using namespace std;
ll power(ll a,ll n) 
{
    if(n==0){
        return 1;
    }
    ll p=power(a,n/2) % M;
    p = (p * p) % M;
    if (n%2==1)
    {
        p=(p*a)%M;
    }
    return p;
}
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}
const int N=1e6+5;
vector <ll> sieve(N,0); 
void si() 
{
    sieve[1]=1;
    for(int i=2;i<N;i++){
        if(sieve[i]==0){
            for(int j=i;j<N;j+=i){
                sieve[j]=i;
            }
        }
    }
}
int isprime(ll n){
    for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    ios;
    ll n,m,x;
    cin>>n>>m>>x;
    vector <ll> c(n);
    vector <vector <ll> > a(n,vector <ll> (m));
    for(int i=0;i<n;i++){
        cin>>c[i];
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    ll loop=pow(2,n)-1;
    ll ans=1e18;
    for(int i=0;i<=loop;i++){
        vector <ll> done(m,0);
        ll cost=0;
        for(int j=0;j<n;j++){
            ll z=pow(2,j);
            if(((z)&(i))){
                cost+=c[j];
                for(int k=0;k<m;k++){
                    done[k]+=a[j][k];
                }
            }
        }
        int flag=1;
        for(int j=0;j<m;j++){
            if(done[j]<x){
                flag=0;
                break;
            }
        }
        if(flag){
            ans=min(ans,cost);
        }
    }
    if(ans==1e18){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;
}