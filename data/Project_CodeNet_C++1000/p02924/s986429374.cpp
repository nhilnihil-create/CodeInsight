#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int NUM = 2e5 + 5;

int main(){
    ios
    int num_tests=1; 
    //cin>>num_tests;
    while(num_tests-->0){
        ll n; cin>>n;
        ll ans=1;
        n--;
        ans+=(n)*(n+1)/2;
        ans-=1;
        cout<<ans;
    }
}
