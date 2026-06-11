#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    int n,k=0;
    
    cin>>n;
  vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    rep(i,n-1){
        if(a[i]==a[i+1]){
            k=1;
        }
    }
    if(k==1){
        cout<<"NO";
    }else{
        cout<<"YES";
    }
}