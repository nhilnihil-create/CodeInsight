#include<iostream>
#include <string>
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define M 1000000007
#define all(v) v.begin(),v.end()
#define fr(a,b,c) for(ll i=a;i<=b;i+=c)
#define inarr(arr,n); for(ll i=0;i<n;i++) cin >> arr[i];
#define outarr(arr,n); for(ll i=0;i<n;i++) cout<<arr[i]<<" ";
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main() {
    ios;
	ll n;
    cin>>n;
    ll ans=0;
    ll n1=n-1;
    if(n>1e6){
    for(int i=2;i<=sqrt(n1);i++){
        if(n1%i==0){
            if(i!=sqrt(n1)){
                ans+=2;
            }
            else{
                ll z=sqrt(n1);
                if(z*z==n1){
                    ans+=1;
                }
            }
        }
    }
    ans+=1;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            if(i!=sqrt(n)){
                ll temp=n;
                ll z1=i;
                ll z2=n/i;
                while(temp>1){
                    if(temp%z1==0){
                    temp=temp/z1;}
                    else{
                        break;
                    }
                }
                if(temp%z1==1){
                    ans+=1;
                }
                temp=n;
                while(temp>1){
                    if(temp%z2==0){
                    temp=temp/z2;}
                    else{
                        break;
                    }
                }
                if(temp%z2==1){
                    ans+=1;
                }
            }
            else{
                ll z=sqrt(n);
                if(z*z==n){
                    ans+=1;
                }
            }
        }
    }
    ans+=1;
    cout<<ans<<endl;}
    else{
        for(int i=2;i<=n;i++){
            if(n%i==1){
                ans+=1;
            }
            else if(n%i==0){
                ll temp=n;
                while(temp>1){
                    if(temp%i==0){
                        temp=temp/i;
                    }
                    else{
                        break;
                    }
                }
                if(temp%i==1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}