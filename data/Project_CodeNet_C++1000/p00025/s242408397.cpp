#include<iostream>
using namespace std;
main(){
	int a[4],b[4];
	while(cin>>a[0]){
		int hit=0,blow=0;
		for(int i=1;i<4;++i)cin>>a[i];
		for(int i=0;i<4;++i)cin>>b[i];
		for(int i=0;i<4;++i){
			if(a[i]==b[i])++hit;
			for(int j=0;j<4;++j){
				if(a[i]==b[j] && i!=j)++blow;
			}
		}
		cout<<hit<<" "<<blow<<endl;
	}
}