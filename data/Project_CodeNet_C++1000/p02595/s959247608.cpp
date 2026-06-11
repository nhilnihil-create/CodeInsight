#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll n,t,x,y,m,d;
int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cin>>t>>d;
      ll ans=0;
      while(t--){
        cin>>x>>y;
        ans+=(x*x+y*y<=d*d);
      } 
      cout<<ans;
}