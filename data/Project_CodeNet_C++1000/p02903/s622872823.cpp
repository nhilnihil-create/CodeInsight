#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1005;
int h,w,a,b,s[N][N];

int main(){
	scanf("%d%d%d%d",&h,&w,&a,&b);
	
	for(int i=1;i<=h;++i){
		for(int j=1;j<=w;++j){
			if(i <= b && j <= a)
				s[i][j] = 1;
			else if(i > b && j > a)
				s[i][j] = 1;
			else
				s[i][j] = 0;
		}
	}
	for(int i=1;i<=h;++i){
		for(int j=1;j<=w;++j)
			cout<<s[i][j];
		cout<<endl;
	}
}