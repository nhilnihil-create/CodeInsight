#include<iostream>
#include<set>
#include<map>

using namespace std;

/*sqrt<3>(NMAX)==100*/

int Nkake[100+1];
int g[1000001]={0};
int k[1000001]={0};

int main(){

	int N;
	
	for(int i=1;i<=200;i++){
		Nkake[i]=i*(i+1)*(i+2)/6;
	}

	for(int i=0;i<=1000000;i++){
		for(int j=1;j<200;j++){
			if(i+Nkake[j]<=1000000){
				if(g[Nkake[j]+i]==0||g[Nkake[j]+i]>g[i]+1) g[Nkake[j]+i]=g[i]+1;
			}
		}
	}

	for(int i=0;i<=1000000;i++){
		for(int j=1;j<200;j++){
			if(Nkake[j]%2==1&&i+Nkake[j]<=1000000){
				if(k[Nkake[j]+i]==0||k[Nkake[j]+i]>k[i]+1) k[Nkake[j]+i]=k[i]+1;
			}
		}
	}

	while(1){
		cin>>N;
		if(N==0) break;

		cout<<g[N]<<" "<<k[N]<<endl;
	}
}