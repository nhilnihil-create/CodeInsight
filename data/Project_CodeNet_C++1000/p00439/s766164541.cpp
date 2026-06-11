#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n,k,i,j,l;
	int a[100000];
	int Smax,S;
	while(l<5){
		cin>>n;
		cin>>k;
		if(n==0){break;}
		
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		for(i=0;i<n-k;i++){
			S=0;
			for(j=i;j<i+k;j++){
				S+=a[j];
			}
			if(Smax<S){Smax=S;}
		}
		
		cout<<Smax<<endl;
		
		l++;
	}
		return 0;
		
}
