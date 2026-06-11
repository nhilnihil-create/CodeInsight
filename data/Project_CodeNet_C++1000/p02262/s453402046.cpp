#include<iostream>
#include<string>
using namespace std;
long d=0,z=0,b[1000000];
void ChentrucTiep(long long a[],long n,long h){
	int x,k;
	for(int i=h;i<n;i++){
		x=a[i];
		k=i-h;
		while(k>=0&& a[k]>x)
		{
			a[k+h]=a[k];
			k-=h;
			d++;
		}
		a[k+h]=x;
	}
}
void shellSort(long long a[],long n){

	for(int i=1;i<=n;)
	{
		b[z]=i;
		z+=1;
		i=i*3+1;
	}
	for(int x=z-1;x>=0;x--)
		ChentrucTiep(a,n,b[x]);
}


int main(){
	long  n;
	long long a[1000000];
	cin >>n;
	for(int i=0;i<n;i++)
		cin >>a[i];
	shellSort(a,n);
	cout << z << endl;
	for(int i=z-1;i>=0;i--){
		cout << b[i];
		if(i)
			cout<<" ";
	}
	cout <<endl << d << endl;
	for(int i=0;i<n;i++){
		cout << a[i] << endl;}

	return 0;
}