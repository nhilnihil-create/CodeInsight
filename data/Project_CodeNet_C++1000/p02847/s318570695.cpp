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
//SUN, MON, TUE, WED, THU, FRI, or SAT.
ll n;
string s;
cin>>s;
if(s=="SUN")	
cout<<7;
else if(s=="MON")	
cout<<6;
else if(s=="TUE")	
cout<<5;
else if(s=="WED")	
cout<<4;
else if(s=="THU")	
cout<<3;
else if(s=="FRI")	
cout<<2;
else if(s=="SAT")	
cout<<1;
	
}
return 0;
}
 
 