#include <iostream>
#include <algorithm>
using namespace std;
int MAX_PRI=123456*2+1;

int main(){
     bool isprime[MAX_PRI];
     for(int i=0;i<MAX_PRI;i++){
	  isprime[i]=true;
     }
     for(int i=2;i*i<=MAX_PRI;i++){
	  if(!isprime[i])continue;
	  for(int j=i*2;j<MAX_PRI;j+=i){
	       isprime[j]=false;
	  }
     }
     isprime[1]=false;

     int in;
     while(cin>>in,in){
	  int a=count(&isprime[in+1],&isprime[in*2+1],true);
	  cout<<a<<endl;
     }
     return 0;
}
	       