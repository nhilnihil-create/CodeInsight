#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string s;
	while(getline(cin, s), s != "."){
		vector<int> a;
		for(int i = 0; i < s.size(); i++){
			switch(s[i]){
			case '(':
			a.push_back(0);
			break;
	
			case '[':
			a.push_back(1);
			break;
	
			case ')':
			if(a.empty()){
				a.push_back(-1);
				break;
			}
			else if(a.back() == 0){
				a.pop_back();
				break;
			}else{
				a.push_back(-1);
				break;
			}

			case ']':
			if(a.empty()){
				a.push_back(-1);
				break;
			}else if(a.back() == 1){
				a.pop_back();
				break;
			}else{
				a.push_back(-1);
				break;
			}
		
			default :
			break;
			}	
			if(!a.empty() && a.back() == -1) break;
		}
		if(a.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}