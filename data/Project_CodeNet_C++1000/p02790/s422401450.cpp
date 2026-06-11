#include<bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  int a,n,i;
  cin>>a>>n;
  if(a>=n){
  	for(i=0;i<a;i++)
  		cout<<n;
  }
  else
	for(i=0;i<n;i++)
  		cout<<a;
  	return 0;
}