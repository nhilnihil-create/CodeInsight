#include <bits/stdc++.h>
using namespace std;

int N,arr[200010];

int main(){
	cin>>N;
	int total=0;
	for(int i=0; i<N; i++){
		cin>>arr[i];
		total=total^arr[i];
	}
	if(total==0){
		sort(arr,arr+N);
		if(N%3==0){
			bool pos=true;
			for(int i=0; i<N; i++){
				if(i<N/3){
					if(arr[i]!=arr[0])pos=false;
				}else if(i<2*N/3){
					if(arr[i]!=arr[N/3])pos=false;
				}else{
					if(arr[i]!=arr[2*N/3])pos=false;
				}
			}
			if(((arr[0]^arr[N/3])^arr[2*N/3])!=0)pos=false;
			if(pos){
				cout<<"Yes"<<'\n';
			}else{
				cout<<"No"<<'\n';
			}
		}else{
			if(arr[N-1]==0){
				cout<<"Yes"<<'\n';
			}else{
				cout<<"No"<<'\n';
			}
		}
	}else{
		cout<<"No"<<'\n';
	}
}