#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,p;
  cin >> n >> p;
  string s;cin>>s;
  long ans=0;
  if(10%p>0){
  	vector<long> vec(p+1,0);
  	int sum=0;
  	vec[0]++;
  	int Pow=1;
  	for(int i=n-1;i>-1;i--){
  	  sum=(sum+(s[i]-'0')*Pow)%p;
 	   vec[sum]++;
 	   Pow=(10*Pow)%p;
  	}
  	for(int i=0;i<p;i++) ans+=vec[i]*(vec[i]-1)/2;
  }
  else{
  	for(int i=n-1;i>-1;i--){
      if((s[i]-'0')%p==0){
        ans+=(i+1);
      }
  	}  
  }
  cout<<ans<<endl;
}