#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n,x,y;
int dis[200020];



int main(){
	cin>>n>>x>>y;
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			dis[min(i-j,abs(x-j)+abs(y-i)+1)] ++;
		}
	}
	
	for (int i=1;i<n;i++){
		cout<<dis[i]<<endl;
	}
	
	return 0; 
} 