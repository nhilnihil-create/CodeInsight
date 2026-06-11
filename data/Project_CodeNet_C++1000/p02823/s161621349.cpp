#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main(){
    int n,a,b,ans,a1,b1,k;
    cin>>n>>a>>b;
    if(a>b){swap(a,b);}
    a1=a,b1=b;
    if(a%2==b%2){ans=(b-a)/2;
        cout<<ans;return 0;
    }
    else{
       ans=a-1;b=b-a+1;
       a=1;
       ans++;b--;
       ans+=(b-1)/2;
       a=a1,b=b1;
       k=n-b;
       a+=k;k++;a++;
       k+=(n-a)/2;
       
       ans=min(ans,k);
    }cout<<ans;
    return 0;}