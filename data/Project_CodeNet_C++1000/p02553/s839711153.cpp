#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,c,d,cnt=0,mx,prd;
  cin>>a>>b>>c>>d;
  mx=a*c;
  long long arr[3]={a*d,b*c,b*d};
  	for(int k=0;k<3;k++){
    	if(arr[k]>mx) mx=arr[k];
      }
  cout<<mx;
	return 0;  
}