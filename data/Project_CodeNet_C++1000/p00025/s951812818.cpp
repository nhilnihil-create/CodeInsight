#include<iostream>
#include<string>

using namespace std;

int main()
{
	int a[4],b[4];
	int ina,inb,i,j;
	while(cin>>ina){
		a[0]=ina;
		int h=0,blow=0;
		for(i=1;i<4;i++)
			cin>>a[i];
		for(j=0;j<4;j++)
			cin>>b[j];
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(a[i]==b[j]){
					if(i==j){
						h++;
						break;
					}
					blow++;
				}
		cout<<h<<" "<< blow<<endl;
	}
	return 0;
}