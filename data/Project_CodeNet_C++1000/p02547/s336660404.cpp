#include<iostream>
#include<string>

using namespace std;

int main()
{
	int N;cin>>N;
	int x[N][2];
	
	for(int i=0;i<N;i++){
		for(int j=0;j<2;j++){
			cin>>x[i][j];
		}
	}
	
	int res=0;
	int a[N]={0};
	for(int i=0;i<N;i++){
		if(x[i][0]==x[i][1]){
			a[i]=1;
			if(i>0){
				a[i]+=a[i-1];
			}
		}
		res=max(res,a[i]);
	}
	
	if(res>2){
		cout<<"Yes";
	} else{
		cout<<"No";
	}
    return 0;
}