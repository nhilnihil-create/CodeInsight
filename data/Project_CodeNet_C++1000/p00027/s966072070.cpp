#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

#define rep(i,n) for(int i=0;i<int(n);++i)

int m,d;

int main(){
	
	while(cin>>m>>d,!(m==0&&d==0)){
		if(m==2){
			d+=31;
		}
		if(m==3){
			d+=60;
		}
		if(m==4){
			d+=91;
		}
		if(m==5){
			d+=121;
		}
		if(m==6){
			d+=152;
		}
		if(m==7){
			d+=182;
		}
		if(m==8){
			d+=213;
		}
		if(m==9){
			d+=244;
		}
		if(m==10){
			d+=274;
		}
		if(m==11){
			d+=305;
		}
		if(m==12){
			d+=335;
		}
		d = d%7;
		if(d==0) cout<<"Wednesday\n";
		if(d==1) cout<<"Thursday\n";
		if(d==2) cout<<"Friday\n";
		if(d==3) cout<<"Saturday\n";
		if(d==4) cout<<"Sunday\n";
		if(d==5) cout<<"Monday\n";
		if(d==6) cout<<"Tuesday\n";
	}
	return 0;
	
}