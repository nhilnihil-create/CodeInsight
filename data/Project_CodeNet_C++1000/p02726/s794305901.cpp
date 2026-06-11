#include<iostream>
#include<vector>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int min(int a,int b){
	if(a<b)return a;
	else return b;
}
int main(){
	int n,x,y;
	cin>>n>>x>>y;
	vector<int>map(n*n);
	rep(i,n){
		for(int j=i;j<n;j++){
			map[i*n+j]=j-i;
			map[j*n+i]=j-i;
		}
	}
	map[(x-1)*n+y-1] = 1;
	map[(y-1)*n+x-1] = 1;
	rep(i,n){
		rep(j,n){
			map[i*n+j] = min(map[i*n+j],map[i*n+x-1]+map[(x-1)*n+j]);
		}
	}
	rep(i,n){
		rep(j,n){
			map[i*n+j] = min(map[i*n+j],map[i*n+(y-1)]+map[(y-1)*n+j]);
		}
	}
	/*
	rep(i,n){
		rep(j,n){
			cout<<map[i*n+j]<<" ";
		}
		cout<<endl;
	}
	*/

	vector<int> a(n,0);
	rep(i,n){
		for(int j=i+1;j<n;j++){
			a[map[i*n+j]-1]+=1;
		}
	}
	rep(i,n-1){
		cout<<a[i]<<endl;
	}

	return 0;
}