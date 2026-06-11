#include<iostream>
#include <string>
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define endl "\n"
#define mp make_pair
#define M 1000000007
#define all(v) v.begin(),v.end()
#define fr(a,b,c) for(ll i=a;i<=b;i+=c)
#define inarr(arr,n); for(ll i=0;i<n;i++) cin >> arr[i];
#define outarr(arr,n); for(ll i=0;i<n;i++) cout<<arr[i]<<" ";
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll inf = 9e18;
const ld pi = 2*acos(0.0);
using namespace std;
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int main(){
    ios_base::sync_with_stdio(false);
    ll t;
    t=1;
    while(t--){
        ll a;
        string s;
        cin>>a>>s;
        if(a>=3200){
            cout<<s<<endl;
        }
        else{
            cout<<"red"<<endl;
        }
    }
    return 0;

}