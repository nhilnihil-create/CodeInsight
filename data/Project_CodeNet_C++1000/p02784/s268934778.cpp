#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int H,N,x=0,y=0;
	cin>>H>>N;
	for(int i=1;i<=N;i++){
	cin>>x;
	y+=x;
	}
	if(y>=H)cout<<"Yes";
	else cout<<"No";
	return 0;
}