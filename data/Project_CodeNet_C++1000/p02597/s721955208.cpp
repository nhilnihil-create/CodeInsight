#include <iostream>
#include <string>
using namespace std;

int main(){
	long long N,W=0,R=0;
	cin>>N;
	string c;
	cin>>c;
	string p;

	for(int i=0;i<N;i++){
		if(c[i]=='R'){
			R++;
		}else{W++;}
	}
	for(int i=0;i<R;i++){
		p.push_back('R');
	}for(int i=R;i<R+W;i++){
		p.push_back('W');
	}
	long long counter=0,M=c.size();
	long datap[c.size()],datac[c.size()];
	for(int i=0;i<M;i++){
		datac[i]=c[i];
		datap[i]=p[i];
		if(datac[i]!=datap[i]){counter++;}
	}
	cout<<counter/2<<endl;
	return 0;
}