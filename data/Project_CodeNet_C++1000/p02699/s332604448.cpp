#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define M 998244353
#define inarr(arr,n); for(ll i=0;i<n;i++) cin >> arr[i];
#define outarr(arr,n); for(ll i=0;i<n;i++) cout<<arr[i]<<" ";
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
int main(){
		ios;
		ll s,w;
		cin>>s>>w;
		if(w>=s){
			cout<<"unsafe"<<endl;
		}
		else{
			cout<<"safe"<<endl;
		}
		return 0;
}