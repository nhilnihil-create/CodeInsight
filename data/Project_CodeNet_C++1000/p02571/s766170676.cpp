#include<iostream>
using namespace std;

int main(){

 string s,t;
  cin>>s>>t;
 
int slen= s.length();
int tlen= t.length();

int ans=9999999;
int count=tlen;
for(int i=0;i<slen-tlen+1;i++){
  count=0;
	for(int j=0,k=i;j<tlen;j++,k++){
    	if(s[k]!=t[j])
          count++;
	}
  ans= min(ans, count);
}
cout<<ans; 
  
return 0;
}