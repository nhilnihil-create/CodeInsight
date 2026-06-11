#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(void){

	string data("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	string conv;
	char inp,inp2;
	string ans;
	int n,m;

	while(1){
		ans=("");
		conv=("..............................................................");
		cin>>n;
		if(n==0) break;
		for(int i=0;i<n;i++){
			cin>>inp>>inp2;
			conv[data.find(inp)]=inp2;
		}

		cin>>m;

		for(int i=0;i<m;i++){
			cin>>inp;
			if(conv[data.find(inp)]!='.') ans+=conv[data.find(inp)];
			else ans+=inp;
		}

		cout<<ans<<endl;
	}

    return 0;
}