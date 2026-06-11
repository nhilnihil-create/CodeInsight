#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
  	int n,ans=0,d=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	   int 	a,b;
	   cin>>a>>b;
	   if(a==b)
	   {
	   	ans+=1;
	   }else{
	   	ans=0;
	   }
	   if(ans==3)
	   {
	   	d=1;
	   }

	}
	if(d!=1)
	{
		cout<<"No";
	}else{
		cout<<"Yes";
	}
	return 0;
}