#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,w,n,x,y,cnt=0;
	cin>>h;
	cin>>w;
	cin>>n;
	x=min(h,w);
	y=max(h,w);
	while(n>=x){
		n-=y;
		cnt++;
	}
	if(n<=0) cout<<cnt<<endl;
	else cout<<cnt+1<<endl;
	return 0;
}
