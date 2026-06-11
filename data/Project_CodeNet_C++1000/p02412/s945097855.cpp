//ITP1_7_B
#include<iostream>
using namespace std;

int main()
{
	int n,x,i,j,k,kumi;
	
	for(;;){
		kumi = 0;
		cin>>n>>x;
		if(n==0&&x==0)
			break;
		for(i=1;i<=n;i++){
			if(i>100)break;
			for(j=i+1;j<=n;j++){
				if(j>100)break;
				for(k=j+1;k<=n;k++){
					if(k>100)break;
					if(i+j+k==x){
						kumi++;
					}
				}
			}
		}
		cout<<kumi<<endl;
	}
	return 0;
}