#include <iostream>
using namespace std;

int main(){
	int a, b, c, d;
  	cin>>a>>b>>c>>d;
  
  	int n1=a/d, n2=c/b;
  	if(a%d>0) n1++;
  	if(c%b>0) n2++;
  
  	if(n1>=n2){
    	cout<<"Yes"<<endl;
    }else{
    	cout<<"No"<<endl;
    }
}