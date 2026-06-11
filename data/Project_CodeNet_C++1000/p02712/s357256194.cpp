#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#define ll long long int 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
      
	ll n;
	cin>>n;
	ll a[n];
	ll i;
	ll p=1;
	ll s2=0;
	for(i=0;i<n;i++){
        a[i]=p;
		p++;
		s2=s2+a[i];
	}
	
	
    ll s=0;
    for(i=0;i<n;i++){

       if(a[i]%3==0&&a[i]%5==0){
	   	s=s+a[i]; 
       }
    
       else if(a[i]%3==0){
        s=s+a[i];
	   }
	  
       else if(a[i]%5==0) {
       s=s+a[i];	
	   }
      
	}
	  cout<<abs(s2-s)<<endl;
      return 0;
  
}