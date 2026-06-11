#include<iostream>
using namespace std;

int main(){
	string s;
	cin>>s;
	bool playable = true;
	for(int i=0; s[i]; i++){
		if((i+1)%2 && s[i]=='L'){
			playable = false;
			break;
		}
		else if((i+1)%2==0 && s[i] == 'R'){
			playable = false;
			break;
		}
	}
	if(!playable) cout<<"No";
	else cout<<"Yes";
}
