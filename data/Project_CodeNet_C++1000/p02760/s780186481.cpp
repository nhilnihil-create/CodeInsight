#include <bits/stdc++.h>
using namespace std;
typedef long double LD; 
typedef long long ll; 
#define int ll 
#define ff(i,a,b) for (int i = a; i < b; i++) 
#define bf(i,a,b) for (int i = a; i >= b; i--) 
#define all(v) v.begin(),v.end() 
#define show(a) for(auto xyz:a)cout<<xyz<<" ";cout<<endl;
#define F first 
#define S second
#define pb push_back
#define mp make_pair
#define lb lower_bound   
#define ub upper_bound
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define one cout<<"-1"<<endl
#define pi 3.141592653589793238
#define intmx INT_MAX 
#define intmi INT_MIN
const int MOD=1e9+7;
int mod(int x){
    return ((x%MOD + MOD)%MOD);
}
int add(int a,int b){
    return mod(mod(a)+mod(b));
}
int mul(int a,int b){
    return mod(mod(a)*mod(b));
}
void solve(){
   int a[3][3];
   ff(i,0,3)
   ff(j,0,3)
   cin>>a[i][j];
   int n;
   cin>>n;
   while(n>0){
       n--;
       int x;
       cin>>x;
       ff(i,0,3){
           ff(j,0,3){
               if(a[i][j]==x)
               a[i][j]=0;
           }
       }
   }
   if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[0][0]==0)
   yes;
   else if(a[2][0]==a[1][1]&&a[1][1]==a[0][2]&&a[2][0]==0)
   yes;
   else{
       ff(i,0,3){
           if(a[i][0]==a[i][1]&&a[i][1]==a[i][2]&&a[i][0]==0){
               yes;
               return;
           }
       }
       ff(i,0,3){
           if(a[0][i]==a[1][i]&&a[1][i]==a[2][i]&&a[0][i]==0){
               yes;
               return;
           }
       }
       no;
       
   }
}
signed main() {
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}