#include<bits/stdc++.h>
using namespace std;
int main(){
	int time[3],p,q,r;
	cin>>p>>q>>r;
	time[0]=p;
	time[1]=q;
	time[2]=r;
	sort(time,time+3);
	cout<<time[0]+time[1]<<endl;
	return 0;
}
