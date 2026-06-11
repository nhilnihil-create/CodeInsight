#include<bits/stdc++.h> 
#define IRONMAN ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define l long long
#define ull unsigned long long int
#define rep(i,n) for(int i=0; i<n; i++)
#define at(i,a) for(auto &i: a)
using namespace std; 
void solve(); 
int main() 
{ 
   IRONMAN

   #ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin); 
   freopen("output.txt", "w", stdout); 
   #endif 
   
   int t=1;//cin>>t; 
   while(t--) 
   { 
      solve(); 
      cout<<"\n"; 
   } 
   
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
} 
void solve() 
{
   l n,sum=0;
   cin>>n;
   for(int i=1; i<=n-1; i++) sum+=(n-1)/i;
   cout<<sum;
} 