#include<bits/stdc++.h>


using namespace std;

int main(int argc, char *argv[])
{
    cout<<setprecision(6)<<fixed;
	double x[1002],y[1002],num=0;
	int cant;
	cin>>cant;
	for(int i=0;i<cant;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<cant;i++)
	{
		cin>>y[i];
	}
	
	for(int i=0;i<cant;i++)//1
	{
		num += abs(x[i]-y[i]);
	}	
	//printf("%.6lf\n",num);
	cout<< num<<endl;
    num=0;
	
	for(int i=0;i<cant;i++)//2
	{
		num += pow(x[i]-y[i],2);
	}	
	//printf("%.6lf\n",sqrt(num));
	cout << sqrt(num)<<endl;
	num=0;
	
	for(int i=0;i<cant;i++)//3
	{
		num += pow(abs(x[i]-y[i]),3);
	}		
	//printf("%.6lf\n",pow(num,(double)1/3));
	cout<< pow(num,(double)1/3)<<endl;
    num=0;
	
	double max=abs(x[0]-y[0]);
	for(int i=1;i<cant;i++)//oo
	{
		if(abs(x[i]-y[i]) > max)
		max=abs(x[i]-y[i]);
	}	
	//printf("%.6lf\n",max);
	cout<< max<<endl;
	num=0;
//	system("pause");
	return 0;
}

