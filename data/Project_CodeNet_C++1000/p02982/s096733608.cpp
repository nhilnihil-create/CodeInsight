#include <bits/stdc++.h>
using namespace std;


#define fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using lli = long long int;
using ll = long long ;
using ld=long double;
using d= double;

bool isPrime(ll n){if(n<2)return false;for(ll i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}

ll lcm(ll x,ll y){
    return (x*y)/(__gcd(x,y));
}

int a[11][11]; 

signed main(){
    fast_IO;
    int t=1;
    //cin>>t;
    while(t--){
         int n;
         int d;
         cin>>n>>d;
         
         for(int i=0;i<n;i++){
             for(int j=0;j<d;j++){
                 cin>>a[i][j];
             }
         }
         ll ans=0;
         for(int i=0;i<n;i++){
             for(int j=i+1;j<n;j++){
                 int sum=0;
                 for(int k=0;k<d;k++){
                     sum+=(a[i][k]-a[j][k])*(a[i][k]-a[j][k]);
                 }
                 ld x=sqrt(sum);
                 int temp=x;
                 bool p=(temp*temp)==sum;
                 ans+=p;
             }
         }
         cout<<ans<<endl;
    }   
    return 0;
}
