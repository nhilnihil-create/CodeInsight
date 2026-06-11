#include <bits/stdc++.h>

#define INF INT_MAX
#define ll long long

using namespace std;

int main(){
	string str;
	while(true){
		getline(cin, str);
		if(str == "."){
			break;
		}
		vector<char> v;	//0:( 1:[
		bool flag = true;
		for(int i = 0;i < str.length();i++){
			if(str[i] == '('){
				v.push_back('(');
			}else if(str[i] == '['){
				v.push_back('[');
			}else if(str[i] == ')'){
				if(v.size() > 0 && v[v.size() - 1] == '('){
					v.pop_back();
				}else{
					flag = false;
					break;
				}
			}else if(str[i] == ']'){
				if(v.size() > 0 && v[v.size() - 1] == '['){
					v.pop_back();
				}else{
					flag = false;
					break;
				}
			}
		}
		if(v.size() > 0){
			flag = false;
		}

		if(flag){
			cout << "yes" << endl;
		}else{
			cout << "no" << endl;
		}
	}

	return 0;
}