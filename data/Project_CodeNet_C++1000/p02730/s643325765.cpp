#include <bits/stdc++.h> 

using namespace std;

int main(){
	string s;
	cin>>s;
	int n=s.length();
	int f=0,l=s.length()-1;
	while(f<l){
		if(s[f]!=s[l]){
			break;
		}
		f++;l--;
	}
	if(f>=l){
		f=0;l=(n-3)/2;
		while(f<l){
			if(s[f]!=s[l]){
				break;
			}
			f++;l--;
		}
		if(f>=l){
			f=(n+1)/2;
			l=n-1;
			while(f<l){
			if(s[f]!=s[l]){
				break;
			}
			f++;l--;
			}
			if(f>=l){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}else{
			cout<<"No"<<endl;
		}
	}
	else{
		cout<<"No"<<endl;
	}
}

