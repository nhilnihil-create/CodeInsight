#include <bits/stdc++.h>
using namespace std;

int main() {
	int H,W;
	int a,b;
	while(true){
		cin>>H>>W;
		if (H==0 && W==0)break;
		for(a=0;a<H;a=a+1){
			for(b=0;b<W;b=b+1){
				cout<<"#";
			}
			cout<<endl;
		}cout<<endl;
	}
}