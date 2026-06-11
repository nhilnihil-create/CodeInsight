#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
  int n;
  cin>>n;	
  string s;
  cin>>s;
  for(int i=0;i<s.length();i++){
  	if(s[i]+n <='Z'){
  		s[i]=s[i]+n;
  	}
  	else {
  		s[i]=s[i]+(n-26);
  	}
  }
  for(auto i :s)cout<<i;
  return 0;
}
  