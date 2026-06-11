#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> ans;

int main(){
	while(1){
		string str;
		getline(cin,str);
		
		if(str == ".")break; 
		
		vector<int> hmk;
		vector<int> hkk;
		bool balance = true;
		
		for(int i = 0;i < str.size();i++){
			if(!balance) break;
			if(str[i] == '(') hmk.push_back(i);
			if(str[i] == '[') hkk.push_back(i);
			if(str[i] == ')'){
				if(hmk.size() == 0) balance = false;
				else{
					for(int j = 0;j < hkk.size();j++){
						if(hmk.back() < hkk[j]){balance = false;break;}
					}
					hmk.pop_back();
				}
			}
			if(str[i] == ']'){
				if(hkk.size() == 0) balance = false;
				else{
					for(int j = 0;j < hmk.size();j++){
						if(hkk.back() < hmk[j]){balance = false;break;}
					}
					hkk.pop_back();
				}
			}
		}
		
		string yn;
		if(hmk.size() == 0 && hkk.size() == 0 && balance) yn = "yes";
		else yn = "no";
		
		ans.push_back(yn);
	}
	for(int i = 0;i < ans.size();i++){
		cout << ans[i] << endl;
	}
	return 0;
}