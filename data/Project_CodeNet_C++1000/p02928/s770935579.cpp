#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

ll mod=1000000007;

int main(){
    ll n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0,c=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) c++;
        }
    }
    ans=c*k%mod;
    c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]>a[j]) c++;
        }
    }
    ans+=k*(k-1)/2%mod*c%mod;
    ans%=mod;
    cout<<ans<<endl;
}