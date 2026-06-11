#include<bits/stdc++.h>
using namespace std;
bool ans[1024][1024];
void merge(int x1,int y1,int x2,int y2){
	if(x1==x2 || y1==y2) return;
	int x=(x1+x2)/2,y=(y1+y2)/2;
	ans[x][y]=0;
	merge(x1,y1,x-1,y-1);
	merge(x1,y+1,x-1,y2);
	merge(x+1,y1,x2,y-1);
	merge(x+1,y+1,x2,y2);
}
int main(){
	int H,W,n;
	cin>>H>>W>>n;
	cout<<min(ceil(1.0*n/H),ceil(1.0*n/W));
	return 0;
}