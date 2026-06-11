#include <iostream>
using namespace std;
int red,green,blue,k;
int main(){
	cin>>red>>green>>blue>>k;
	for(int i=0;i<k;i++){
		if(green<=red) green*=2;
		else blue*=2;
		if(i==k) break;
	}
	if(blue>green&&green>red) cout<<"Yes";
	else cout<<"No";
	return 0;
}