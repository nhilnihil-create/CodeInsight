# include <bits/stdc++.h>
using namespace std;


int main (){
	int a,b,c,min=700000;
	cin>>a>>b>>c;
	int aux=a+b;
	int aux2=a+c;
	int aux3=b+c;
	int ar[3];
	ar[0]=aux;
	ar[1]=aux2;
	ar[2]=aux3;
	for(int i=0;i<3;i++){
		if(ar[i]<min){
			min=ar[i];
		}
	}

	cout<<min; 
	
}