#include <iostream>
#include<string>
using namespace std;
 
 bool F(int n){
	 bool b=false;
	 string s;
	 s=to_string(n);
	 for(int i=0;i<s.size();i++){
		 if(s[i]=='3')b=true;
		 }
		return b; 
	 }
 
int main(){
    int n;
    cin>>n;
  for(int i=1;i<=n;i++){
	  if(i%3==0||F(i)==true){
		  cout<<" "<<i;
	  }else{
	  }
  }
  cout<<endl;
    return 0;
}
