#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int T,N,M,C,mi=1,fi=0;
int a[20][20];
int b[20],c[20];
//int retu(int i){

//}
int main(){
	cin>>T>>N>>M;
	for(int i=0;i<T;i++){
		cin>>b[i];mi+=b[i];
		for(int j=0;j<N;j++){
			cin>>a[i][j];
		}
	}
	fi=mi;
	int l=pow(2,double(T));
	for(int k=0;k<(1<<T);k++){
		int sum=0;
		for(int i=0;i<20;i++)c[i]=0;
		for(int j=0;j<T;j++){
			if((k>>j)&1){
				sum+=b[j];
				for(int i=0;i<N;i++){
					//cout<<a[j][i]<<" ";
					c[i]+=a[j][i];
				}
				//cout<<endl;
			}
		}
		int f=1;
		for(int i=0;i<N;i++){
			if(c[i]<M){f=0;break;f=0;}
			//cout<<c[i]<<" ";
		}
		//cout<<endl;continue;
		if(f)mi=min(mi,sum);
	}
	if(mi==fi)cout<<"-1\n";
	else cout<<mi<<endl;
}