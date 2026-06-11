#include <iostream>
using namespace std;
string lower(string str);

main(){
	int count=0;
	string W,T;
	cin>>W;
	W=lower(W);
	while(cin>>T&&T!="END_OF_TEXT"){
		int index=0;
		if(W==lower(T)){
			count++;
		}
	}
	cout<<count<<endl;
}

string lower(string str){
	int length=str.length();
	for(int i=0;i<length;i++){
		if('A'<=str[i]&&str[i]<='Z'){
			str[i]+=0x20;
		}
	}
	return str;
}