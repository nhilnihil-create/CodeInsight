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
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
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
   double n,x;
   int t;
   cin>>n>>x>>t;
   int y=ceil(n/x);
   cout<<y*t<<endl;
}
signed main() {
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}