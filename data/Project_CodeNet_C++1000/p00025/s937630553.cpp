#include<bits/stdc++.h>
using namespace std;

int main(){
	string sa,sb;
	int ca=0,cb=0;
	while(getline(cin,sa),getline(cin,sb)){
		if(sa[0]==sb[0]){ca++;}
		if(sa[2]==sb[2]){ca++;}
		if(sa[4]==sb[4]){ca++;}
		if(sa[6]==sb[6]){ca++;}
		
		if(sa[0]==sb[2]||sa[0]==sb[4]||sa[0]==sb[6]){cb++;}
		if(sa[2]==sb[0]||sa[2]==sb[4]||sa[2]==sb[6]){cb++;}
		if(sa[4]==sb[0]||sa[4]==sb[2]||sa[4]==sb[6]){cb++;}
		if(sa[6]==sb[0]||sa[6]==sb[4]||sa[6]==sb[2]){cb++;}
		
		cout<<ca<<" "<<cb<<endl;
		ca=0;cb=0;
		}
		return 0;
	}