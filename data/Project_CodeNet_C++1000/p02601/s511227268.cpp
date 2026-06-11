#include <iostream>
using namespace std;
int main(){
	int r,g,b,k,s=0;
	cin>>r>>g>>b>>k;
	while(true){
		if(g<=r){
			g=g*2;
			s++;
		}
		else if(b<=g){
			b=b*2;
			s++;
		}
		else{
			b=b*2;
			s++;
		}
		if(s==k) break;
	}
	if(b>g && g>r) cout<<"Yes";
	else cout<<"No";
	return 0;
}