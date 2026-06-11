#include<bits/stdc++.h>
using namespace std;
main(void){
	int T;cin>>T;
	double x1,x2,x3,x4,y1,y2,y3,y4;
	for(int t=1;t<=T;t++){
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		if(abs((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4))<0.0000000001)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}