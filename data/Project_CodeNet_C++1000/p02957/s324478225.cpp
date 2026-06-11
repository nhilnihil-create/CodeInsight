#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main(){
  long long int a,b;
  cin>>a>>b;
  
  long long int ans = (a+b)/2;
  if(abs(a-ans) == abs(b-ans)){
  	cout<<ans;
  }else if(abs(a-ans+1)== abs(b-ans+1)){
  	cout<<ans+1;
  } else if(abs(a-ans-1)== abs(b-ans-1)){
  	cout<<ans-1;
  }else{
  	cout<<"IMPOSSIBLE";
  }
}