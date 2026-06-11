#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main(){
	string G;
	getline(cin,G);
	for(int i=0;i<G.size();i++){
		if(isupper(G[i])){
			G[i]=tolower(G[i]);
		}else if(islower(G[i])){
			G[i]=toupper(G[i]);
		}
	}
	cout<<G<<endl;
	return 0;
}