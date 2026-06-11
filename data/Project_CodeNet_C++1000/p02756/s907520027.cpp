#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector <int> n;

int main(){
	string s,c;
	bool rev=true;
	int q,t,f;
	cin>>s>>q;
	for(int i=0;i<q;i++){
		cin>>t;
		if(t==1){
			if(rev){
				rev=false;
			}else{
				rev=true;
			}
		}else{
			cin>>f>>c;
			if(f==1){
				if(rev){
					c+=s;
					s=c;
				}else{
					s+=c;
				}
			}else{
				if(rev){
					s+=c;
				}else{
					c+=s;
					s=c;
				}
			}
		}
	}
	if(rev){
		cout<<s<<endl;
	}else{
		for(int i=s.size()-1;i>=0;i--){
			cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}