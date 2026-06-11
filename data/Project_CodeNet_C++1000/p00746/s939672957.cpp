#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	int x[200],y[200];
	while(true){
	cin>>n;
	if(n==0)
		break;
	x[0]=0,y[0]=0;
	int mx=0,dx=0,my=0,dy=0;
	int d,e;
	for(int i=1;i<n;i++){
		cin>>d>>e;
		x[i]=x[d],y[i]=y[d];
		if(e==0)
			x[i]--;
		if(e==1)
			y[i]--;
		if(e==2)
			x[i]++;
		if(e==3)
			y[i]++;
		if(x[i]>mx)
			mx=x[i];
		if(x[i]<dx)
			dx=x[i];
		if(y[i]>my)
			my=y[i];
		if(y[i]<dy)
			dy=y[i];
	}
	cout<<mx-dx+1<<" "<<my-dy+1<<endl;
	}
    return 0;
}