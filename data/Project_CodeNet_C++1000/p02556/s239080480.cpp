#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define mod 1000000007
#define pb push_back  
#define endl "\n"
#define fi first
#define se second 
#define ll long long
#define inf 9000000000000000000
#define PI 3.14159265359

int power(int a,int b,int m=mod)
{
     if(b==0)	return 1;
     if(b==1)	return a;
	 int res=power(a,b/2,m);
	 res=(res*res)%m;
     if(b&1)	res=(res*a)%m;
     return res;
}
int modinv(int a,int m=mod){ return power(a,m-2,m);}
int add(int a,int b,int m=mod){	int c=(a%m+b%m);	if(c>=m)	c-=m;	return c;}
int sub(int a,int b,int m=mod){	int c=(a%m-b%m);	if(c<0)		c+=m;	return c;}
int mul(int a,int b,int m=mod){	return (a*b)%m;}


int32_t main()
{
   IOS
    
   int n,i;
   cin>>n;
   vector<int>v1,v2;
   for(i=0;i<n;i++)
   {
   	int x,y;
   	cin>>x>>y;
   	
   	v1.push_back(x-y);
   	v2.push_back(x+y);
   }
  
   sort(v1.begin(),v1.end());
   sort(v2.begin(),v2.end());
   
   cout<<max(abs(v1[v1.size()-1] - v1[0]),abs(v2[v2.size()-1] - v2[0]))<<endl;
}