#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define pb push_back

#define N 1000000
int arr[N];

void eratosthenes(){
	rep(i,N){
		arr[i]=1;
	}

	for(int i=2;i<sqrt(N);i++){
		if(arr[i]){
			for(int j=0;i*(j+2)<N;j++){
				arr[i*(j+2)]=0;
			}
		}
	}
}


int main(){

	int a,b;
	while(1){
		cin>>a;
		if(a==0)break;
		b=a*2;

		eratosthenes();

		int count=0;

		arr[0]=0;
		arr[1]=0;

		// rep(i,a*2){
		// 	cout<<i<<" "<<arr[i]<<endl;
		// }

		repi(i,a+1,b+1){
			if(arr[i]==1)count++;
		}

		// cout<<"count:"<<count<<endl;
		cout<<count<<endl;

	}
}