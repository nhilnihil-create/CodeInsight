#include<iostream>
using namespace std;

main(){
	int W,H,x,y,r;
	
	cin>>W>>H>>x>>y>>r;
	
	if(x-r<0 || x-r>W || x+r>W || x+r<0 || y-r<0 ||y+r>H || y+r>H || y+r<0) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}