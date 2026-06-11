#include <stdio.h>
#include <iostream>

using namespace std;
void call(int n){
	int i=1;
	do{
		int x=i;
		if(x%3==0){
			cout<<" "<<i;
		}else{
			do
			{
				if(x%10==3){
					cout<<" "<<i;	
					break;
				}
				x/=10;
			}while(x);
		}
	}while(++i<=n); 
	cout << endl;
 }
 
 int main()
{
 	int n;
 	scanf("%d",&n);
 	call(n);
}

