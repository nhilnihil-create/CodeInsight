#include <iostream>
using namespace std;
string str;

void replaceAll(string &s,string from,string to){
	int pos=s.find(from);
	for(;pos!=string::npos;pos=s.find(from)){
		s.replace(pos,from.size(),to);
	}
}
void solve(){
	string s="";
	for(string::iterator it=str.begin();it!=str.end();it++){
		if((*it)=='('||(*it)==')'||(*it)=='['||(*it)==']')s+=(*it);
	}
	while(s!=""){
		string _s=s;
		if(s[0]==')'||s[0]==']')break;
		replaceAll(s,"()","");
		replaceAll(s,"[]","");
		if(s==_s)break;
	}
	if(s=="")cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}
int main(){
	while(getline(cin,str)&&str[0]!='.'){
		solve();
	}

	return 0;
}