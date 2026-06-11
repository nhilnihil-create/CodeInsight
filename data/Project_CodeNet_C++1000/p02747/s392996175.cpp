#include<bits/stdc++.h>
using namespace std;
int main(){
	string S;
	cin>>S;
	if((S.size()&1) || S.size()==0) return puts("No"),0;
	for(int i=0;i<S.size();++i)
		if(S[i]!='h'&&S[i]!='i') return puts("No"),0;
	for(int i=0;i<S.size();++i){
		char ch=(i&1)?'i':'h';
		if(ch!=S[i]) return puts("No"),0;
	} 
	cout<<"Yes";
	return 0;
} 