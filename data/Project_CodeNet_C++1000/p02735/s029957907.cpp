#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <numeric>
#include <iomanip>
#include <fstream>
using namespace std;
int main(){
	int h,w;
	char a[100][100];
	int d[100][100];
	cin>>h>>w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>a[i][j];
		}
	}
	d[0][0]=0;
	for(int i=1;i<w;i++){
		if(a[0][i]!=a[0][i-1]){
			d[0][i]=d[0][i-1]+1;
		}else{
			d[0][i]=d[0][i-1];
		}
	}
	for(int i=1;i<h;i++){
		if(a[i][0]!=a[i-1][0]){
			d[i][0]=d[i-1][0]+1;
		}else{
			d[i][0]=d[i-1][0];
		}
	}
	for(int i=1;i<h;i++){
		for(int j=1;j<w;j++){
			if(a[i][j]!=a[i-1][j]){
				d[i][j]=d[i-1][j]+1;
			}else{
				d[i][j]=d[i-1][j];
			}
			if(a[i][j]!=a[i][j-1]){
				d[i][j]=min(d[i][j],d[i][j-1]+1);
			}else{
				d[i][j]=min(d[i][j],d[i][j-1]);
			}
		}
	}
	int ans=d[h-1][w-1];
	if(ans==0){
		if(a[0][0]=='.'){
			cout<<0<<endl;
		}else{
			cout<<1<<endl;
		}
	}else{
		if(a[0][0]=='.'&&a[h-1][w-1]=='.'){
			cout<<ans/2<<endl;
		}else if(a[0][0]=='#'&&a[h-1][w-1]=='#'){
			cout<<ans/2+1<<endl;
		}else{
			cout<<(ans-1)/2+1<<endl;
		}
	}
	return 0;
}