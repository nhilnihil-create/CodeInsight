#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    ll n;
    cin>>n;
    ll a[300005],b[300005];
    for(int i=0;i<n;i++){int x;
        cin>>x;
        a[x-1]++;
    }
    sort(a,a+n,greater<int>());
    int j=n-1;
    ll sum=0;
    for(int i=1;i<=n;i++){
        
        while(j>=0 && a[j]<i){
            sum+=a[j];
            j--;
        }
        
        b[i]= sum/i +(j+1);
    }
 
    j=n;
    for(int i=1;i<=n;++i){
        
      while(j>=1 && b[j]<i) {
             
             j--;
             
      }  
        cout<<j<<"\n";
        
    }

}