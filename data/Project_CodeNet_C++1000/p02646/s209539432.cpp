#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ull unsigned long long 
#define int long long 
#define pb push_back 
#define mp make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define MAX 1e18
#define PI 3.14159265
const int mod = 1e9 + 7;

int power(int x, int y) 
{ 
   int res = 1;      
  
   
    while (y > 0) 
    { 
       
        if (y & 1) 
            res = (long long)(res*x); 
  
 
        y = y>>1; 
 
        if (x<=100000000)
        x = (long long)(x*x);
 
        //cout<<x<<'\n'; 
    } 
    return res; 
} 




void solve()
{
    int a,b;
    int v,w;
    int t;
    cin>>a>>v;
    cin>>b>>w;
    cin>>t;
    if(w<v){
        int ans=abs(b-a);
        int rex=(v-w)*t;
        if(ans<=rex){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        return;
    }
    else{
        cout<<"NO"<<endl;
    }
 return;
}


int32_t main()
{
    solve();
    return 0;
}