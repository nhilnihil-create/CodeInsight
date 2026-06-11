#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<ll> x(n);
    ll sum=accumulate(a.begin(),a.end(),0LL);
    x[0]=sum;
    for(int i=1;i<n;i+=2){
        x[0]-=2*a[i];
    }
    for(int i=0;i<n-1;i++){
        x[i+1]=2*a[i]-x[i];
    }
    for(ll i : x) cout<<i<<endl;
}