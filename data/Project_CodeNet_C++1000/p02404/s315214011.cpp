//ITP1_5_B
#include<iostream>
using namespace std;

int main()
{
	int h,w,i,j;
	
	while(1){
	cin>>h>>w;
	
	if(h==0&&w==0)
		break;
	
	for(i=0;i<h;i++){
		if(i==0||i==h-1){
			for(j=0;j<w;j++){
				cout<<"#";
				if(j==w)
				cout<<endl;
					}
				}
		if(i!=0&&i!=h-1){
			for(j=0;j<w;j++){
				if(j==0||j==w-1)
					cout<<"#";
				else cout<<".";
				}
			}
		if(j==w) cout<<endl;
			}
		cout<<endl;
	}
	return 0;
}