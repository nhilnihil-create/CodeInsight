#include<iostream>
using namespace std;
int IsChar(int i,int j,int h,int w)
{
	if (i==0 || i==h-1)
		return 1;
	else if(j==0 || j==w-1)
		return 1;
	else 
		return 0;
}
void Draw(int h,int w)
{
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if (IsChar(i,j,h,w)==1)
				cout<<"#";
			else
				cout<<".";
		}		
		cout<<endl;
	}	
}

int main()
{
	int h ,w;
	while(true){
		cin>>h>>w;
		if(h==0&&w==0)
			break;
		Draw(h,w);
		cout<<endl;	
	}	
	return 0;
}
