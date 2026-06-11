#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define set_zero(a) memset(a,0,sizeof(a));
#define ll long long
#define PI 2 * acos(0.0)
#define MAX 1000000000
#define INF 1000000 
#define M 1000000007
using namespace std;
bool sortinrev(const pair<ll,ll> &a,  
               const pair<ll,ll> &b) 
{ 
       return (a.first > b.first); 
} 
int main(){
   fast_io
   ll a,b,c;
   cin>>a>>b>>c;
   ll sum = a+b+c;
   if(sum >= 22){
      cout<<"bust"<<endl;
   }
   else{
      cout<<"win"<<endl;
   }
   return 0;
}