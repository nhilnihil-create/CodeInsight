#include<iostream>

using namespace std;

int main()
{
	int a=0,b=0,c=0,d=0,e=0,n,count;
	for(int i=1;i<=50;i++){
		cin>>n;
		do{
		if((a+b+c+d)==n){
			count++;
		}
		if(a==9 && b==9 && c==9 && d==9){
			e=1;
		}
	
		else if(b==9 && c==9 && d==9){
			a++;
			b=0,c=0,d=0;
		}
		else if(c==9 && d==9){
			b++;
			c=0,d=0;
		}
		else if(d==9){
			c++;
			d=0;
		}
		else{
			d++;
		}
	
		}while(e==0);
		cout<<count<<endl;
		count=0,a=0,b=0,c=0,d=0,e=0;
	}
	return 0;
}