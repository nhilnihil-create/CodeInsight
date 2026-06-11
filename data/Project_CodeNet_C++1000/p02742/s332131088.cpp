#include <iostream> 
#include <math.h>
using namespace std;
long long int H,W;

int main()
{
	cin >> W >> H;

 	if(W==1||H==1) cout<<1<<endl;
	else if(W%2==0) cout<<W/2*H<<endl;
	else 
	{
		if(H%2==0)
			cout<<(W/2+1)*H/2+(W/2)*H/2<<endl;
		else
			cout<<(W/2+1)*(H/2+1)+(W/2)*(H/2)<<endl;
	}	

}

/*
int main()
{
	long double A,B,C;
	cin>>A>>B>>C;
	if((C-A-B)>0&&(C-A-B)*(C-A-B)>4*A*B)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}*/