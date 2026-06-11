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
/*
2
ABCXYZ*/
ll n,i;
cin>>n;
string s;
cin>>s;
fo(i,s.length())
{char d=((s[i]-65+n))%26+65;
	cout<<d;
}
	ee;
	
}
return 0;
}







