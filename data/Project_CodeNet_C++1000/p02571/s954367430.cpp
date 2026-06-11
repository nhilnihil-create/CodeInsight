#include<iostream>
using namespace std;
int main(){
	char a[1001],b[1001];
	long least,var,lena=0,lenb=0,l=1;
	cin>>a>>b;                       
	for(;b[lenb];lenb++);                  
	for(;a[lena];lena++);                
	for(int i=0;i<=lena-lenb;i++){
		var=0;
		for(int j=0;j<lenb;j++){                 
			if(a[i+j]!=b[j]){              
				var++;
			}
		}
		                                   
		if(var<least||l)least=var;
		if(l)l=0;

		
	}
	cout<<least;
	return 0;
}