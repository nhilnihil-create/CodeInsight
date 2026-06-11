#include<iostream>
#include<math.h>

using namespace std;

int main(){
	int n,d,x[10][10],i,j,t,ans=0;
	double sum=0,num;

	cin>>n>>d;

	for(i=0;i<n;i++){
		for(j=0;j<d;j++){
			cin>>x[i][j];
		}
	}

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(t=0;t<d;t++){
				sum+=pow(x[i][t]-x[j][t],2);
			}

			num=sqrt(sum);

			if(floor(num)==num){
				ans++;
			}

			sum=0;
		}
	}

	cout<<ans<<endl;

	return 0;
}