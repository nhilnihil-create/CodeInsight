#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll n,t,x,y,m,q;

int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cin>>n;
      ll a[n];
      for(int i=0;i<n;i++){
        cin>>a[i];
      }
      ll ans=0;
      for(int i=2;i<n;i++){
        for(int j=1;j<i;j++){
          for(int k=0;k<j;k++){
            if(a[i]<a[j]+a[k] && a[j]<a[i]+a[k] && a[k]<a[j]+a[i]) 
              ans+=(a[i]!=a[j] && a[j]!=a[k] && a[k]!=a[i]);
          }
        }
      }
      cout<<ans;
}