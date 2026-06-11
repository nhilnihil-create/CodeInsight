#include <iostream>
using namespace std;

int main() {
	int h,w,ch=1;
	while(1){
		cin>>h>>w;
		if(h==0)
			break;
		for(int i=1; i<=h; i++){
			for(int j=1; j<=w; j++){
				if(ch==1){
					cout<<'#';
					ch=0;
				}
				else{
					cout<<'.';
					ch=1;
				}
			}
			if(i%2)
				ch=0;
			else
				ch=1;
			cout<<'\n';
		}
		ch=1;
		cout<<'\n';
	}
	return 0;
}