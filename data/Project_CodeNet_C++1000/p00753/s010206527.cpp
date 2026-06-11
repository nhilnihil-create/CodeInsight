#include <iostream>
using namespace std;
int main(){
	int p[246913];
	for(int i=2;i<=246912;i++){
		p[i]=1;
	}
	for(int i=2;i<246913;i++){
		if(i>2&&i%2==0){
			p[i]=0;
		}
		else if(i>3&&i%3==0){
			p[i]=0;
		}
		else{
			int ii=i/12;
			for(int j=1;j<ii+2;j++){
				if(i%(6*j+1)==0){
					p[i]=0;
					break;
				}
				else if(i%(6*j-1)==0){
					p[i]=0;
					break;
				}
			}
		}
		p[5]=1;
		p[7]=1;
		p[13]=1;
	}
	int n;
	while(cin>>n){
		if(n==0) break;
		int c=0;
		for(int i=n+1;i<=2*n;i++){
			c=c+p[i];
		}
		cout<<c<<endl;
	}
    return 0;
}