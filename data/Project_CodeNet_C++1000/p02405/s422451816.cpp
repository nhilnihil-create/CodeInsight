#include<iostream>
using namespace std;
 
int main(){
    while(1){
        int d,c;
        cin >> d >>c;
         
        if(d==0 && c==0)break;
        for(int j=0;j<d;j++)
		{
			for(int i=0;i<c;i++)
			{
				if((i+j)%2==0)
				{
					cout<<"#";
				}
				else
				{
					cout<<".";
				}
				
			}
			cout<<"\n";
		}
		cout<<"\n";
    }
     
    return 0;
}