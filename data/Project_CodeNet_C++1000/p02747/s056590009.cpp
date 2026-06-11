#include<bits/stdc++.h> 

using namespace std;

int main(){ 
	cin.tie(0);
	ios::sync_with_stdio(0);

	string s;
	cin>>s;
	bool p=0; 
	if(s.size() & 1){ 
		cout<<"No";
		return 0;
	}
	for(char c:s){ 
		if(!p){ 
			if(c!='h'){ 
				cout<<"No";
				return 0;
			} 
		}else{ 
			if(c!='i'){ 
				cout<<"No";
				return 0;
			}
		} 
		p=!p;
	} 
	cout<<"Yes"; 

	return 0;
}
