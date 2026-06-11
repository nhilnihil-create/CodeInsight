/*                                  /   \                                 */      
/*                                 /*****\                               */
/*     Jai Shree Mataji           /       \ |\| |_| $ |-| K             */
#include<vector>
#include<iostream>
#include<algorithm>                
#include<string.h>                 
#include<bits/stdc++.h>            
#include<cstring>                  
#include<map>                     
#include<cmath>                  
#include<set>
using namespace std;            
#define ll long long int        
#define ld long double
#define MOD 1000000007 
#define PI 3.1415926535897932384626433832795                                               
#define YY cout<<"YES"
#define NN cout<<"NO"
#define ee cout<<"\n"
#define ne cout<<"-1"
#define pb push_back 
#define fi first
#define se second
#define mkp make_pair    
#define sall(v ) sort(v.begin(), v.end())      
#define all(v )  v.begin(), v.end()      
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#define vl vector<ll>
#define vll vector< pair<ll,ll> > 
#define mpl map<ll, ll>
#define pr pair<ll,ll>
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) {return (a.second < b.second); }
ll pow1(ll n,ll p){if(p==0)return 1;ll x=pow1(n, p/2);x=(x*x)%MOD;if(p%2==0) return x%MOD;else return (x*n)%MOD;}
ll pd(ll x,ll y){if(x%y==0) return x/y;else return x/y+1;}  
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);	
	  ll t=1;


//	   cin>>t;
	      while(t--)
{
ll n,m,j,k,l,i;
/*
3
1 1
2 4
3 2*/
cin>>n;
ll a[n],b[n];
vl v1,v2;
//ma=-MOD,mb=-MOD;
fo(i,n)	
{cin>>a[i]>>b[i];
	v1.pb(a[i]+b[i]);
	v2.pb(a[i]-b[i]);
//	ma=max(ma,a[i]);
}
sall(v1);
sall(v2);
ll ans=max(v1[n-1]-v1[0],v2[n-1]-v2[0]);
cout<<ans;
ee;
}
return 0;
}







