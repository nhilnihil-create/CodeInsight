#include<iostream>
using namespace std;

void Draw(int h,int w)
{
	char startop,op;
	
	for(int i=0;i<h;i++){
		if (i%2==0)
			startop='#';
		else
			startop='.';
		op=startop;
		for(int j=0;j<w;j++){
			cout<<op;
			if (op=='#')
				op='.';
			else
				op='#';
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
