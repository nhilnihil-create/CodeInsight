#include<iostream>
using namespace std;
main(){
	double xy[4][2],p[2],tmp[2];
	int n;
	cin>>n;
	for(int loop=0;loop<n;++loop){
		for(int i=0;i<4;++i){
			for(int j=0;j<2;++j){
				cin>>xy[i][j];
			}
		}
		for(int i=0;i<2;++i){
			tmp[0]=xy[i*2][1]-xy[i*2+1][1];
			tmp[1]=xy[i*2][0]-xy[i*2+1][0];
			p[i]=tmp[0]/tmp[1];
			//cout<<xy[i*2][0]<<" "<<xy[i*2+1][0]<<endl;
		}
		if(p[1]==p[0])cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}