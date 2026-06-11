#include<iostream>
using namespace std;
int main(){
	
	int a,b,number=0,count=0;
	cin>>a>>b;
	
	
	if(b==1)
	 cout<<0;
	 else{
		 
		while(number<b){
			if(number+a<b){
				
				number+=(a-1);
			
			}
			else{
			
				number+=a;
			
			}
			count++;
		}
		cout<<count;
	}
    
}


