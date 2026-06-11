#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	
	while(1){
		stack <int> sta;
		int si = 0, f = 1;
		getline(cin, str);
		
		if(str == ".") break;
		
		si = str.size();
		
		for(int i = 0; i < si; i++){
			switch(str[i]){
				case '[': sta.push(1); break;
				case ']': if(!sta.empty()){if(sta.top() != 1)f = 0; sta.pop();}else f = 0;break;
				case '(': sta.push(2); break;
				case ')': if(!sta.empty()){if(sta.top() != 2)f = 0; sta.pop();}else f = 0;break;
			}
			if(f == 0) break;
		}
		
		if(!sta.empty())f = 0;
		
		if(f) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
		
	}
	return 0;
}
