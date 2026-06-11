//ITP1_5_C
#include<iostream>
using namespace std;

int main()
{
	int h,w,i,j,k;
	
	while(1){
	cin>>h>>w;
		if(h==0&&w==0)
			break;
		for(i=0;i<h;i++){
		k=0;
			if(0==i%2)
				for(j=0;j<w;j++,k++){
					if(0==k%2)
						cout<<"#";
					if(1==k%2)
						cout<<".";
					if(j==w-1)
						cout<<endl;
						}
			if(1==i%2)
				for(j=0;j<w;j++,k++){
					if(0==k%2)
						cout<<".";
					if(1==k%2)
						cout<<"#";
					if(j==w-1)
						cout<<endl;
						}
			if(i==h-1)
				cout<<endl;	
			}
	}
	return 0;
}